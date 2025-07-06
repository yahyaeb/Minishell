/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_handle_basic_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:07:30 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/16 08:45:55 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	setup_child_fds(int prev_fd, int i, int total, int pipe_fd[2])
{
	if (prev_fd != -1)
	{
		dup2(prev_fd, STDIN_FILENO);
		close(prev_fd);
	}
	if (i < total - 1)
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT_FILENO);
		close(pipe_fd[1]);
	}
}

static void	close_parent_pipe_ends(int i, int *prev_fd,
			int pipe_fd[2], int total)
{
	if (*prev_fd != -1)
		close(*prev_fd);
	if (i < total - 1)
	{
		close(pipe_fd[1]);
		*prev_fd = pipe_fd[0];
	}
}

static void	wait_for_all_children_basic(t_shell *sh)
{
	int	status;

	while (wait(&status) > 0)
	{
		if (WIFEXITED(status))
			sh->last_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			sh->last_exit_status = 128 + WTERMSIG(status);
	}
}

static void	exec_pipeline_child_pipe(t_exec_context *ctx)
{
	char	*cmd_path;

	setup_child_fds(ctx->prev_fd, ctx->cmd_index,
		ctx->pipeline->cmd_count, ctx->pipe_fd);
	if (is_builtin(ctx->pipeline->cmds[ctx->cmd_index].argv[0]))
		exit(exec_builtin_in_child(ctx->pipeline->cmds[ctx->cmd_index].argv,
				ctx->sh));
	cmd_path = get_cmd_path(ctx->pipeline->cmds[ctx->cmd_index].argv[0],
			ctx->env);
	if (!cmd_path)
		exit(127);
	execve(cmd_path, ctx->pipeline->cmds[ctx->cmd_index].argv, ctx->env);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

void	run_pipeline_basic_pipeline(t_pipeline *p, char **env, t_shell *sh)
{
	int				i;
	int				prev_fd;
	int				pipe_fd[2];
	pid_t			pid;
	t_exec_context	ctx;

	prev_fd = -1;
	if (!validate_pipeline_commands(p, sh))
		return ;
	if (!validate_all_non_builtins(p, env, sh))
		return ;
	i = 0;
	while (i < p->cmd_count)
	{
		open_pipe_if_needed(i, p->cmd_count, pipe_fd);
		init_ctx_pipeline_one(&ctx, prev_fd, pipe_fd, env);
		init_ctx_pipeline_two(&ctx, sh, p, i);
		pid = fork();
		if (pid == 0)
			exec_pipeline_child_pipe(&ctx);
		close_parent_pipe_ends(i, &prev_fd, pipe_fd, p->cmd_count);
		i++;
	}
	wait_for_all_children_basic(sh);
}

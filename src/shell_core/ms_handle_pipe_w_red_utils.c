/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_handle_pipe_w_red_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 07:13:38 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/06 19:42:56 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	exit_if_redirection_failed(int redir_status, int is_last_cmd)
{
	if (redir_status < 0)
	{
		if (is_last_cmd)
			exit(1);
		else
			exit(0);
	}
}

void	execute_command_red(t_pipeline_loop_context *ctx)
{
	t_pipeline	*p;
	int			i;
	char		*cmd_path;

	i = ctx->cmd_index;
	p = ctx->pipeline;
	if (!p->cmds[i].argv || !p->cmds[i].argv[0])
		exit(1);
	if (is_builtin(p->cmds[i].argv[0]))
		exit(exec_builtin_in_child(p->cmds[i].argv, ctx->sh));
	cmd_path = get_cmd_path(p->cmds[i].argv[0], ctx->env);
	if (!cmd_path)
		exit(127);
	execve(cmd_path, p->cmds[i].argv, ctx->env);
	perror("execve failed");
	exit(EXIT_FAILURE);
}

void	handle_parent_pipe_closing(t_pipeline_loop_context *ctx)
{
	if (ctx->prev_fd != -1)
		close(ctx->prev_fd);
	if (ctx->cmd_index < ctx->pipeline->cmd_count - 1)
	{
		ctx->prev_fd = ctx->pipe_fd[0];
		close(ctx->pipe_fd[1]);
	}
	else
		ctx->prev_fd = -1;
}

void	run_pipeline_with_redir(t_pipeline *p, char **env, t_shell *sh)
{
	int		last_pid;

	last_pid = pipeline_fork_loop(p, env, sh);
	wait_for_pipeline(p, last_pid, sh);
}

void	execute_child_pipeline_cmd(t_pipeline_loop_context *ctx)
{
	setup_redirections_red(ctx);
	setup_child_fds_red(ctx);
	execute_command_red(ctx);
}

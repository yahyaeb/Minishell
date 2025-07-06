/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_handle_pipe_w_red_loop.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 19:31:19 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/06 19:44:54 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	init_ctx(t_pipeline *p, char **env, t_shell *sh,
		t_pipeline_loop_context *ctx)
{
	ctx->pipeline = p;
	ctx->prev_fd = -1;
	ctx->sh = sh;
	ctx->env = env;
	ctx->cmd_index = 0;
}

int	pipeline_fork_loop(t_pipeline *p, char **env, t_shell *sh)
{
	pid_t					last_pid;
	pid_t					pid;
	t_pipeline_loop_context	ctx;

	last_pid = -1;
	init_ctx(p, env, sh, &ctx);
	while (ctx.cmd_index < p->cmd_count)
	{
		if (ctx.cmd_index < p->cmd_count - 1 && pipe(ctx.pipe_fd) < 0)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
		pid = fork();
		if (pid == 0)
			execute_child_pipeline_cmd(&ctx);
		else if (ctx.cmd_index == p->cmd_count - 1)
			last_pid = pid;
		handle_parent_pipe_closing(&ctx);
		ctx.cmd_index++;
	}
	return (last_pid);
}

void	setup_redirections_red(t_pipeline_loop_context *ctx)
{
	t_pipeline		*p;
	int				i;

	i = ctx->cmd_index;
	p = ctx->pipeline;
	ctx->redir_status = open_redirection_fds_mixed(&p->cmds[i],
			&ctx->in_fd, &ctx->out_fd, ctx->sh);
	exit_if_redirection_failed(ctx->redir_status, i == p->cmd_count - 1);
}

static void	close_pipes(t_pipeline_loop_context *ctx)
{
	close(ctx->pipe_fd[0]);
	close(ctx->pipe_fd[1]);
}

void	setup_child_fds_red(t_pipeline_loop_context *ctx)
{
	t_pipeline	*p;
	int			i;

	i = ctx->cmd_index;
	p = ctx->pipeline;
	if (ctx->in_fd != -1)
	{
		dup2(ctx->in_fd, STDIN_FILENO);
		close(ctx->in_fd);
	}
	else if (ctx->prev_fd != -1)
		dup2(ctx->prev_fd, STDIN_FILENO);
	if (ctx->out_fd != -1)
	{
		dup2(ctx->out_fd, STDOUT_FILENO);
		close(ctx->out_fd);
	}
	else if (i < p->cmd_count - 1)
		dup2(ctx->pipe_fd[1], STDOUT_FILENO);
	if (ctx->prev_fd != -1)
		close(ctx->prev_fd);
	if (i < p->cmd_count - 1)
		close_pipes(ctx);
}

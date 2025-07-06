/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_handle_basic_pipe_utils.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 10:06:50 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/05 10:06:59 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	init_ctx_pipeline_one(t_exec_context *ctx,
			int prev_fd, int pipe_fd[2], char **env)
{
	ctx->prev_fd = prev_fd;
	ctx->pipe_fd[0] = pipe_fd[0];
	ctx->pipe_fd[1] = pipe_fd[1];
	ctx->env = env;
}

void	init_ctx_pipeline_two(t_exec_context *ctx,
			t_shell *sh, t_pipeline *p, int i)
{
	ctx->pipeline = p;
	ctx->cmd_index = i;
	ctx->sh = sh;
}

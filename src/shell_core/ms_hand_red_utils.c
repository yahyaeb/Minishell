/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_hand_red_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:00:45 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/11 11:20:59 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	setup_redirections(int in_fd, int out_fd)
{
	if (in_fd != -1)
	{
		dup2(in_fd, STDIN_FILENO);
		close(in_fd);
	}
	if (out_fd != -1)
	{
		dup2(out_fd, STDOUT_FILENO);
		close(out_fd);
	}
}

void	cleanup_pipeline_on_error(t_pipeline *p, t_commands *cmd, char **argv)
{
	free_cmds_files_and_limiter(cmd);
	free(cmd);
	free(argv);
	free(p);
}

void	append_token_to_argv(char **argv, char *token, int *arg_i)
{
	argv[*arg_i] = ft_strdup(token);
	(*arg_i)++;
}

t_pipeline	*parse_redirection_only(char **tokens)
{
	t_parse_redir_ctx	ctx;

	ctx.p = ft_calloc(1, sizeof(t_pipeline));
	ctx.cmd = ft_calloc(1, sizeof(t_commands));
	ctx.argv = ft_calloc(128, sizeof(char *));
	if (!ctx.p || !ctx.cmd || !ctx.argv)
		return (NULL);
	ctx.p->cmds = ctx.cmd;
	ctx.i = 0;
	ctx.arg_i = 0;
	while (tokens[ctx.i])
	{
		if (exec_parse_redir_loop(&ctx, tokens) != 0)
			return (NULL);
	}
	if (ctx.arg_i == 0)
	{
		cleanup_pipeline_on_error(ctx.p, ctx.cmd, ctx.argv);
		return (NULL);
	}
	ctx.argv[ctx.arg_i] = NULL;
	ctx.cmd->argv = ctx.argv;
	ctx.p->cmds = ctx.cmd;
	ctx.p->cmd_count = 1;
	return (ctx.p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_hand_red_exec.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:03:51 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/04 17:25:27 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	handle_redir_in(t_pipeline *p, char **tokens, int *i)
{
	if (tokens[*i + 1])
	{
		p->cmds->infile = ft_strdup(tokens[++(*i)]);
		return (2);
	}
	else
	{
		perror("Error: missing infile\n");
		return (1);
	}
}

int	handle_append(t_pipeline *p, char **tokens, int *i)
{
	if (tokens[*i + 1])
	{
		p->cmds->outfile = ft_strdup(tokens[++(*i)]);
		p->cmds->append = true;
		return (2);
	}
	else
	{
		perror("Error: missing outfile\n");
		return (1);
	}
}

int	handle_redir_out(t_pipeline *p, char **tokens, int *i)
{
	if (tokens[*i + 1])
	{
		p->cmds->outfile = ft_strdup(tokens[++(*i)]);
		p->cmds->append = false;
		return (2);
	}
	else
	{
		perror("Error: missing outfile\n");
		return (1);
	}
}

int	exec_parse_redir_loop(t_parse_redir_ctx *ctx, char **tokens)
{
	int	ret;

	while (tokens[ctx->i])
	{
		ret = handle_redirection_token(ctx->p, tokens, &ctx->i);
		if (ret == 1)
		{
			cleanup_pipeline_on_error(ctx->p, ctx->cmd, ctx->argv);
			return (1);
		}
		else if (ret == 0)
			append_token_to_argv(ctx->argv, tokens[ctx->i], &ctx->arg_i);
		ctx->i++;
	}
	return (0);
}

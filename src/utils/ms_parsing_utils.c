/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 07:51:46 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/05 07:52:38 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	handle_redir_out_parsing(t_commands *cmd,
			t_parse_state *fd, char **tokens, int *i)
{
	fd->test_fd = open(tokens[*i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd->test_fd < 0)
	{
		perror(tokens[*i + 1]);
		free(cmd->argv);
		cmd->argv = NULL;
		return (false);
	}
	close(fd->test_fd);
	free(fd->last_outfile);
	fd->last_outfile = ft_strdup(tokens[++(*i)]);
	fd->last_append = false;
	return (true);
}

bool	handle_append_parsing(t_commands *cmd,
			t_parse_state *fd, char **tokens, int *i)
{
	fd->test_fd = open(tokens[*i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd->test_fd < 0)
	{
		perror(tokens[*i + 1]);
		free(cmd->argv);
		cmd->argv = NULL;
		return (false);
	}
	close(fd->test_fd);
	free(fd->last_outfile);
	fd->last_outfile = ft_strdup(tokens[++(*i)]);
	fd->last_append = true;
	return (true);
}

bool	handle_redirection_parsing(t_parse_context *parse)
{
	if (is_token_control_char(parse->tokens[parse->i],
			CC_REDIR_IN) && parse->tokens[parse->i + 1])
		return (handle_redir_in_parsing(parse->cmd,
				parse->fd, parse->tokens, &parse->i));
	else if (is_token_control_char(parse->tokens[parse->i],
			CC_REDIR_OUT) && parse->tokens[parse->i + 1])
		return (handle_redir_out_parsing(parse->cmd,
				parse->fd, parse->tokens, &parse->i));
	else if (is_token_control_char(parse->tokens[parse->i],
			CC_APPEND) && parse->tokens[parse->i + 1])
		return (handle_append_parsing(parse->cmd, parse->fd,
				parse->tokens, &parse->i));
	return (true);
}

bool	handle_token(t_parse_context *parse)
{
	if (is_token_control_char(parse->tokens[parse->i], CC_REDIR_IN)
		|| is_token_control_char(parse->tokens[parse->i], CC_REDIR_OUT)
		|| is_token_control_char(parse->tokens[parse->i], CC_APPEND))
	{
		if (!handle_redirection_parsing(parse))
			return (false);
	}
	else if ((unsigned char)parse->tokens[parse->i][0] < 32
			&& parse->tokens[parse->i][1] == '\0')
		parse->i++;
	else
		parse->cmd->argv[(parse->argc)++] = ft_strdup(parse->tokens[parse->i]);
	return (true);
}

bool	parse_tokens_loop(t_commands *cmd, t_parse_state *fd, char **tokens)
{
	t_parse_context	ctx;

	ctx.cmd = cmd;
	ctx.fd = fd;
	ctx.tokens = tokens;
	ctx.i = 0;
	ctx.argc = 0;
	while (ctx.tokens[ctx.i])
	{
		if (!handle_token(&ctx))
			return (false);
		ctx.i++;
	}
	ctx.cmd->argv[ctx.argc] = NULL;
	return (true);
}

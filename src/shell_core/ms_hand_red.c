/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_hand_red.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:07:30 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/13 15:56:21 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static bool	check_heredoc_variables(char **tokens, int *i,
			t_pipeline *p, int cmd_index)
{
	if (tokens[*i + 1])
	{
		p->cmds[cmd_index].infile = ft_strdup("here_doc");
		p->cmds[cmd_index].limiter = ft_strdup(tokens[++(*i)]);
		p->cmds[cmd_index].append = false;
		(*i)++;
		return (true);
	}
	return (false);
}

static bool	check_redir_in_variables(char **tokens, int *i,
			t_pipeline *p, int cmd_index)
{
	if (tokens[*i + 1])
	{
		p->cmds[cmd_index].infile = ft_strdup(tokens[++(*i)]);
		(*i)++;
		return (true);
	}
	return (false);
}

static bool	check_redir_out_variables(char **tokens, int *i,
			t_pipeline *p, int cmd_index)
{
	if (tokens[*i + 1])
	{
		p->cmds[cmd_index].outfile = ft_strdup(tokens[++(*i)]);
		p->cmds[cmd_index].append = false;
		(*i)++;
		return (true);
	}
	return (false);
}

bool	handle_redirection_tokens(char **tokens, int *i,
	t_pipeline *p, int cmd_index)
{
	if (is_token_control_char(tokens[*i], CC_HEREDOC))
		return (check_heredoc_variables(tokens, i, p, cmd_index));
	if (is_token_control_char(tokens[*i], CC_REDIR_IN))
		return (check_redir_in_variables(tokens, i, p, cmd_index));
	if (is_token_control_char(tokens[*i], CC_REDIR_OUT))
		return (check_redir_out_variables(tokens, i, p, cmd_index));
	if (is_token_control_char(tokens[*i], CC_APPEND))
	{
		if (tokens[*i + 1])
		{
			p->cmds[cmd_index].outfile = ft_strdup(tokens[++(*i)]);
			p->cmds[cmd_index].append = true;
			(*i)++;
			return (true);
		}
		return (false);
	}
	return (false);
}

int	handle_redirection_token(t_pipeline *p, char **tokens, int *i)
{
	if (is_token_control_char(tokens[*i], CC_REDIR_IN))
		return (handle_redir_in(p, tokens, i));
	else if (is_token_control_char(tokens[*i], CC_APPEND))
		return (handle_append(p, tokens, i));
	else if (is_token_control_char(tokens[*i], CC_REDIR_OUT))
		return (handle_redir_out(p, tokens, i));
	else
		return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipex_count_cmds.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 17:08:27 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/05 06:55:57 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	parse_next_command(char **tokens, int *i, t_pipeline *p, int *cmd_i)
{
	int	count;

	while (tokens[*i] && is_token_control_char(tokens[*i], CC_PIPE))
		(*i)++;
	count = count_command_tokens(tokens, *i);
	if (count == 0)
		return ;
	p->cmds[*cmd_i].argv = extract_command_args(tokens, i, count);
	if (!p->cmds[*cmd_i].argv)
		return ;
	(*cmd_i)++;
	if (tokens[*i] && is_token_control_char(tokens[*i], CC_PIPE))
		(*i)++;
}

void	count_up_and_set_command(int *count, int *in_cmd)
{
	(*count)++;
	*in_cmd = 1;
}

int	count_cmds(char **tokens)
{
	int	i;
	int	count;
	int	in_cmd;

	in_cmd = 0;
	count = 0;
	i = 0;
	while (tokens[i])
	{
		if (is_token_control_char(tokens[i], CC_PIPE))
			in_cmd = 0;
		else if (control_token(tokens[i]))
		{
			if (tokens[i + 1])
				i++;
			in_cmd = 0;
		}
		else
		{
			if (!in_cmd)
				count_up_and_set_command(&count, &in_cmd);
		}
		i++;
	}
	return (count);
}

int	count_command_tokens(char **tokens, int start)
{
	int	count;

	count = 0;
	while (tokens[start]
		&& !is_token_control_char(tokens[start], CC_PIPE))
	{
		if ((is_token_control_char(tokens[start], CC_REDIR_IN)
				|| is_token_control_char(tokens[start], CC_REDIR_OUT)
				|| is_token_control_char(tokens[start], CC_APPEND))
			&& tokens[start + 1])
		{
			start += 2;
			continue ;
		}
		count++;
		start++;
	}
	return (count);
}

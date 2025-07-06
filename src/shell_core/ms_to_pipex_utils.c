/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_to_pipex_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:38:07 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/07 21:49:55 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	has_heredoc(t_pipeline *p)
{
	int	i;

	i = 0;
	while (i < p->cmd_count)
	{
		if (p->cmds[i].limiter)
			return (true);
		i++;
	}
	return (false);
}

bool	is_builtin(const char *cmd)
{
	if (!cmd)
		return (false);
	if (ft_strcmp(cmd, "cd") == 0
		|| ft_strcmp(cmd, "echo") == 0
		|| ft_strcmp(cmd, "env") == 0
		|| ft_strcmp(cmd, "pwd") == 0
		|| ft_strcmp(cmd, "export") == 0
		|| ft_strcmp(cmd, "unset") == 0
		|| ft_strcmp(cmd, "exit") == 0
		|| ft_strchr(cmd, '=') != NULL
		|| (cmd[0] == CC_VAR_TO_INTERPRET)
		|| ((cmd[0] == CC_VAR_TO_INTERPRET) && (cmd[1] == '?'))
		|| (cmd[0] == '$')
		|| ((cmd[0] == '$') && (cmd[1] == '?'))
		|| (cmd[0] == '/')
		|| (cmd[0] == '.' && cmd[1] && cmd[1] == '/')
		|| (cmd[0] == '.' && cmd[1] && cmd[1] == '.'
			&& cmd[2] && cmd[2] == '/')
	)
		return (true);
	return (false);
}

int	handle_pipe_token(char **tokens, int *i, int *current_cmd)
{
	if (is_token_control_char(tokens[*i], CC_PIPE))
	{
		(*current_cmd)++;
		(*i)++;
		return (1);
	}
	return (0);
}

int	init_argv_if_needed(t_pipeline *p, char **tokens, int i, int current_cmd)
{
	int	count;

	if (!p->cmds[current_cmd].argv)
	{
		count = count_command_tokens(tokens + i, 0);
		if (count > 0)
		{
			p->cmds[current_cmd].argv = malloc(sizeof(char *) * (count + 1));
			if (!p->cmds[current_cmd].argv)
				return (1);
			p->cmds[current_cmd].argv[0] = NULL;
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_classifier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:07:30 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/12 22:38:52 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	is_first_token_redirection(char **tokens)
{
	if (!tokens[0])
		return (0);
	return (
		is_token_control_char(tokens[0], CC_REDIR_IN)
		|| is_token_control_char(tokens[0], CC_REDIR_OUT)
		|| is_token_control_char(tokens[0], CC_APPEND)
	);
}

static int	token_redirection(char **tokens, int i)
{
	if (!tokens[i])
		return (0);
	return (
		is_token_control_char(tokens[i], CC_REDIR_IN)
		|| is_token_control_char(tokens[i], CC_REDIR_OUT)
		|| is_token_control_char(tokens[i], CC_APPEND)
	);
}

t_cmd_type	classify_command(char **tokens)
{
	t_cmd_flags	flags;
	int			i;

	i = 0;
	memset(&flags, 0, sizeof(flags));
	flags.first_is_redir = is_first_token_redirection(tokens);
	while (tokens[i])
	{
		if (check_pipe(tokens, i, &flags))
			return (MIXED_INVALID);
		else if (check_heredoc(tokens, &i, &flags))
			return (MIXED_INVALID);
		else if (check_redirection(tokens, &i, &flags))
			return (MIXED_INVALID);
		else
			check_normal_cmd(tokens, i, &flags);
		i++;
	}
	return (check_cmd_class(flags));
}

int	check_redirection(char **tokens, int *i, t_cmd_flags *flags)
{
	if (token_redirection(tokens, *i))
	{
		flags->has_redir = 1;
		if (!tokens[*i + 1])
			return (1);
		if (token_redirection(tokens, *i + 1))
			flags->consecutive_redirs = 1;
		(*i)++;
	}
	return (0);
}

char	*shell_find_cmd_path(char *cmd, char **paths)
{
	int		i;
	char	*temp;
	char	*full;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (!temp)
			return (NULL);
		full = ft_strjoin(temp, cmd);
		free(temp);
		if (!full)
			return (NULL);
		if (access(full, X_OK) == 0)
			return (full);
		free(full);
		i++;
	}
	return (NULL);
}

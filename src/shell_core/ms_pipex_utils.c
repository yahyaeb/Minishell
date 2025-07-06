/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_pipex_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:57:41 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/04 17:20:54 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	is_token_control_char(char *token, char ctrl_char)
{
	char	*ctrl_char_str;
	int		res;

	ctrl_char_str = ft_chrtostr(ctrl_char);
	res = ft_strcmp(token, ctrl_char_str);
	free(ctrl_char_str);
	return (res == 0);
}

int	control_token(char *token)
{
	return (is_token_control_char(token, CC_PIPE)
		|| is_token_control_char(token, CC_REDIR_IN)
		|| is_token_control_char(token, CC_REDIR_OUT)
		|| is_token_control_char(token, CC_APPEND));
}

char	**extract_command_args(char **tokens, int *i, int count)
{
	char	**argv;
	int		j;

	j = 0;
	argv = malloc(sizeof(char *) * (count + 1));
	if (!argv)
		return (NULL);
	while (tokens[*i] && !control_token(tokens[*i]))
	{
		if (control_token(tokens[*i])
			&& tokens[*i + 1])
		{
			*i += 2;
			continue ;
		}
		argv[j++] = ft_strdup(tokens[*i]);
		(*i)++;
	}
	argv[j] = NULL;
	return (argv);
}

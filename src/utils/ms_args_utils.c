/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_args_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 07:48:47 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/05 07:50:19 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	count_pipes(char **tokens)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (tokens[i])
	{
		if (is_token_control_char(tokens[i], CC_PIPE))
			count++;
		i++;
	}
	return (count);
}

int	count_args(char **tokens)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (tokens[i])
	{
		if ((is_token_control_char(tokens[i], CC_REDIR_IN)
				|| is_token_control_char(tokens[i], CC_REDIR_OUT)
				|| is_token_control_char(tokens[i], CC_APPEND))
			&& tokens[i + 1])
			i += 2;
		else if ((unsigned char)tokens[i][0] < 32 && tokens[i][1] == '\0')
			i++;
		else
		{
			count++;
			i++;
		}
	}
	return (count);
}

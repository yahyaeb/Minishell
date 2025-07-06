/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_interpreter_spaces.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 15:38:23 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/15 15:41:38 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	protect_spaces_in_assignements(char *str)
{
	int	i;
	int	in_value;

	in_value = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '=' && !in_value)
			in_value = 1;
		else if (in_value && str[i] == ' ')
			str[i] = CC_SPACE_IN_QUOTE;
		i++;
	}
}

void	restore_protected_spaces(char **args)
{
	int	i;
	int	j;

	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == CC_SPACE_IN_QUOTE)
				args[i][j] = ' ';
			j++;
		}
		i++;
	}
}

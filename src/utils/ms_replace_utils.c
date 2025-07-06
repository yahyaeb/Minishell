/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_replace_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 11:40:44 by mmalie            #+#    #+#             */
/*   Updated: 2025/05/20 13:10:44 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	ft_replace_if_space(char *cur_c, char new_c)
{
	if (ft_isspace(*cur_c))
		*cur_c = new_c;
}

void	ft_replace_char(char *cur_c, char new_c)
{
	*cur_c = new_c;
}

void	ft_replace_chars_in_str(char *str, char cur_c, char new_c)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			if (str[i] == cur_c)
				ft_replace_char(&str[i], new_c);
			i++;
		}
	}
	return ;
}

void	ft_replace_all_chars(char **input_args, char old, char new)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input_args[i])
	{
		j = 0;
		while (input_args[i][j])
		{
			if (input_args[i][j] == old)
				input_args[i][j] = new;
			j++;
		}
		i++;
	}
}

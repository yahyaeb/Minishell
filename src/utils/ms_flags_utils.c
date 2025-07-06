/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_flags_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 13:36:08 by mmalie            #+#    #+#             */
/*   Updated: 2025/05/17 23:07:36 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// If delim is repeated or met at end or start, flag for future reconversion.
// mode: [s]tart, [m]iddle, [e]nd, keep [f]irst only
void	ft_flag_delim(char *str, char delim, char flag, char *mode)
{
	size_t	i;

	i = 0;
	if (ft_strchr(mode, 'f') != NULL)
	{
		ft_flag_all_but_first(str, delim, flag);
		return ;
	}
	if (ft_strchr(mode, 's') != NULL && str[0] == delim)
		str[0] = flag;
	while (str[i + 1] != '\0')
	{
		if (ft_strchr(mode, 'm') != NULL
			&& str[i] == delim && str[i + 1] == delim)
			str[i] = flag;
		i++;
	}
	if (ft_strchr(mode, 'e') != NULL && str[i] == delim)
		str[i] = flag;
}

void	ft_flag_all_but_first(char *str, char delim, char flag)
{
	bool	is_first;
	size_t	i;

	i = 0;
	is_first = true;
	while (str[i] != '\0')
	{
		if (str[i] == delim && is_first == false)
			ft_replace_char(&str[i], flag);
		else if (str[i] == delim && is_first == true)
			is_first = false;
		i++;
	}
	return ;
}

void	ft_unflag_delim(char *str, char delim, char flag)
{
	size_t	i;

	i = 0;
	if (!str || str[i] == '\0')
		return ;
	while (str[i] != '\0')
	{
		if (str[i] == flag)
			str[i] = delim;
		i++;
	}
}

char	**split_input_arg(t_shell *sh, size_t *i)
{
	char	**split_str;

	split_str = NULL;
	ft_flag_delim(sh->input_args[(*i)], '=', CC_EXTRA_DELIM, "f");
	split_str = ft_split(sh->input_args[(*i)], '=');
	ft_unflag_delim(split_str[1], '=', CC_EXTRA_DELIM);
	if (!split_str)
		return (NULL);
	return (split_str);
}

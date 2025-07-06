/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_strs_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:12:12 by mmalie            #+#    #+#             */
/*   Updated: 2025/05/17 23:07:23 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// Return the number of strings pointed by strs
size_t	ft_strslen(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i] != NULL)
		i++;
	return (i);
}

// Copy the content of strs (here: env) to a t_list.
int	ft_strstolist(t_list **list, char **strs, size_t nb_strs, char delim)
{
	char	**split_str;
	t_list	*node;
	size_t	i;

	i = 0;
	node = NULL;
	split_str = NULL;
	while (i < nb_strs)
	{
		if (!delim)
			node = ft_lstnew((char *)strs[i]);
		else
		{
			ft_flag_delim(strs[i], delim, CC_EXTRA_DELIM, "sme");
			split_str = ft_split(strs[i], delim);
			if (!split_str)
				return (-1);
			node = ft_lstnew((char **)split_str);
		}
		if (!node)
			return (-1);
		ft_lstadd_back(list, node);
		i++;
	}
	return (0);
}

// Return the first str in strs that either contains no c or at forbidden_pos
char	**ft_strschr(char **strs, char c, int forbidden_pos)
{
	int	i;

	i = 0;
	if (forbidden_pos >= 0)
	{
		while (strs[i] != NULL)
		{
			if (((int)ft_strlen(strs[i]) >= forbidden_pos)
				&& (strs[i][forbidden_pos] == c))
				return (&(strs[i]));
			i++;
		}
	}
	i = 0;
	while (strs[i] != NULL)
	{
		if (ft_strchr(strs[i], c) == NULL)
			return (&(strs[i]));
		i++;
	}
	return (NULL);
}

char	**ft_strsdup(char **strs)
{
	char	**dup_strs;
	size_t	nb_strs;
	size_t	i;
	size_t	j;

	nb_strs = ft_strslen(strs);
	dup_strs = malloc(sizeof(char *) * (nb_strs + 1));
	if (!dup_strs)
		return (NULL);
	i = 0;
	while (i < nb_strs)
	{
		dup_strs[i] = ft_strdup(strs[i]);
		if (!dup_strs[i])
		{
			j = 0;
			while (j < i)
				free(dup_strs[j++]);
			free(dup_strs);
			return (NULL);
		}
		i++;
	}
	dup_strs[i] = NULL;
	return (dup_strs);
}

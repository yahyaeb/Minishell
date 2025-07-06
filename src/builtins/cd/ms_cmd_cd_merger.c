/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_cd_merger.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 19:22:29 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/17 19:51:07 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

char	*merge_pwd_and_path(char **pwd_split, char **path_split,
		int i, int j)
{
	char	**result;
	char	*final_result;

	result = malloc(sizeof(char *) * 1024);
	if (!result)
		return (NULL);
	init_to_null(result);
	while (pwd_split[i])
	{
		result[i] = ft_strdup(pwd_split[i]);
		if (!result[i])
			return (free_incomplete_strs(result, i));
		i++;
	}
	if (try_merge(path_split, result, i, j) != 0)
		return (free_incomplete_strs(result, i));
	final_result = join_parts(result, 0);
	free_args(result);
	return (final_result);
}

void	init_to_null(char **result)
{
	int	i;

	i = 0;
	while (i < 1024)
	{
		result[i] = NULL;
		i++;
	}
}

int	try_merge(char **path_split, char **result, int i, int j)
{
	while (path_split[j])
	{
		if (!ft_strcmp(path_split[j], "..") && i > 0)
			i--;
		else if (ft_strcmp(path_split[j], ".") && path_split[j][0])
			result[i++] = ft_strdup(path_split[j]);
		if (!result[i])
			return (1);
		j++;
	}
	result[i] = NULL;
	return (0);
}

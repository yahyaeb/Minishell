/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_cd_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 00:03:54 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/17 19:36:42 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

char	*join_parts(char **parts, int i)
{
	char	*res;
	char	*tmp;
	char	*tmp2;

	res = ft_strdup("/");
	if (!res)
		return (NULL);
	while (parts[i])
	{
		tmp = ft_strjoin(res, parts[i]);
		free(res);
		if (!tmp)
			return (NULL);
		if (parts[i + 1])
			tmp2 = ft_strjoin(tmp, "/");
		else
			tmp2 = ft_strdup(tmp);
		free(tmp);
		if (!tmp2)
			return (NULL);
		res = tmp2;
		i++;
	}
	return (res);
}

int	append_and_replace(char **dst, char *suffix)
{
	char	*temp;

	temp = ft_strjoin(*dst, suffix);
	if (!temp)
		return (0);
	free(*dst);
	*dst = temp;
	return (1);
}

void	update_if_exists(char **last_existing, char *current)
{
	if (access(current, F_OK) == 0)
	{
		free(*last_existing);
		*last_existing = ft_strdup(current);
	}
}

char	*find_last_existing_dir(char *path, int i)
{
	char	**path_parts;
	char	*current_path;
	char	*last_existing;

	last_existing = NULL;
	current_path = ft_strdup("/");
	path_parts = ft_split(path, '/');
	if (!path_parts || !current_path)
	{
		free_args(path_parts);
		free(current_path);
		return (NULL);
	}
	while (path_parts[i])
	{
		if (!append_and_replace(&current_path, path_parts[i]))
			break ;
		update_if_exists(&last_existing, current_path);
		if (!append_and_replace(&current_path, "/"))
			break ;
		i++;
	}
	free(current_path);
	free_args(path_parts);
	return (last_existing);
}

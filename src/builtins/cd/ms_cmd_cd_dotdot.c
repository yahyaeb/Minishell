/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_cd_dotdot.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:18:31 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/17 05:31:23 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

char	*handle_cd_dotdot_case(char *pwd, char **pwd_split, char **path_split)
{
	static int	cd_up_count = 0;
	static int	deleted_dirs = 0;
	char		*current_path;
	int			i;

	i = 0;
	if (cd_up_count == 0)
	{
		current_path = ft_strdup("/");
		if (test_pwd_split(pwd_split, current_path, i, &deleted_dirs) != 0)
			return (NULL);
	}
	cd_up_count++;
	if (cd_up_count >= deleted_dirs)
	{
		reset_count_and_free(&cd_up_count, &deleted_dirs,
			pwd_split, path_split);
		return (find_last_existing_dir(pwd, 0));
	}
	free_args(pwd_split);
	free_args(path_split);
	ft_printf("cd: error retrieving current directory: getcwd: "
		"cannot access parent directories: No such file or directory\n");
	return (ft_strjoin(pwd, "/.."));
}

int	test_pwd_split(char **pwd_split, char *current_path,
	int i, int *deleted_dirs)
{
	while (pwd_split[i])
	{
		if (!append_and_replace(&current_path, pwd_split[i]))
		{
			free(current_path);
			return (1);
		}
		if (access(current_path, F_OK) != 0)
			(*deleted_dirs)++;
		if (!append_and_replace(&current_path, "/"))
		{
			free(current_path);
			return (1);
		}
		i++;
	}
	free(current_path);
	return (0);
}

void	reset_count_and_free(int *cd_up_count, int *deleted_dirs,
		char **pwd_split, char **path_split)
{
	*cd_up_count = 0;
	*deleted_dirs = 0;
	free_args(pwd_split);
	free_args(path_split);
}

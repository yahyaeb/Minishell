/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_cd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 00:03:54 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/17 19:17:21 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	cmd_cd(t_shell *sh)
{
	char	*cwd;
	char	*path;
	t_list	*home_var;
	int		res;
	char	*user_path;

	home_var = ft_getenv("HOME", &sh->this_env);
	path = NULL;
	res = cd_set_path(sh, home_var, &path);
	if (res < 2)
		return (res);
	user_path = ft_strdup(path);
	cwd = store_cwd(NULL);
	if (!cwd)
	{
		cwd = fallback_to_pwd_if_cwd_fails(sh);
		if (!cwd)
			return (ms_err("cd", "", PWD_NON_SET, 1));
	}
	if (cd_process_path(sh, cwd, path, user_path) != 0)
		return (handle_cd_path_failure(user_path, cwd));
	free(user_path);
	free(cwd);
	return (0);
}

int	cd_set_path(t_shell *sh, t_list *home_var, char **path)
{
	if (!sh->input_args[1] || ft_strcmp(sh->input_args[1], "~") == 0)
	{
		if (!home_var)
			return (ms_err("cd", "", HOME_NON_SET, 1));
		else if (home_var && !((char **)home_var->content)[1])
			return (0);
		*path = ((char **)home_var->content)[1];
	}
	else if (sh->input_args[2])
		return (ms_err("cd", "", TOO_MANY_ARGS, 1));
	else
		*path = sh->input_args[1];
	return (2);
}

char	*fallback_to_pwd_if_cwd_fails(t_shell *sh)
{
	t_list	*pwd_var;
	char	*cwd;

	pwd_var = ft_getenv("PWD", &sh->this_env);
	if (pwd_var != NULL && ((char **)pwd_var->content)[1])
		cwd = ft_strdup(((char **)pwd_var->content)[1]);
	else
		cwd = NULL;
	return (cwd);
}

int	cd_process_path(t_shell *sh, char *cwd, char *path, char *user_path)
{
	t_list	*oldpwd_var;

	if (path[0] == '.')
		return (handle_relative_cd(sh, cwd, path, user_path));
	if (ft_strcmp(path, "-") == 0)
	{
		oldpwd_var = ft_getenv("OLDPWD", &sh->this_env);
		if (!oldpwd_var)
			return (ms_err("cd", "", OLDPWD_NON_SET, 1));
		path = ((char **)oldpwd_var->content)[1];
	}
	return (change_directory(sh, cwd, path, user_path));
}

int	handle_cd_path_failure(char *user_path, char *cwd)
{
	free(user_path);
	free(cwd);
	return (1);
}

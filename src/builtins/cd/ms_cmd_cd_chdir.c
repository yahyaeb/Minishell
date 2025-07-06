/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_cd_chdir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 00:03:54 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/16 22:52:42 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	change_directory(t_shell *sh, char *cwd, char *path, char *user_path)
{
	char	*trimmed;
	char	*logical_pwd;
	t_list	*home_var;

	logical_pwd = NULL;
	if (!path)
	{
		home_var = ft_getenv("HOME", &sh->this_env);
		if (!home_var)
			return (ms_err("cd", "", HOME_NON_SET, 1));
		path = ((char **)home_var->content)[1];
	}
	if (access(path, F_OK) != 0)
		return (ms_err("cd", path, NO_FILE_OR_DIR, 1));
	if (chdir(path) != 0)
		return (cd_case_invalid_chdir(sh, cwd, user_path, logical_pwd));
	trimmed = store_cwd(NULL);
	if (!trimmed)
		return (cd_case_invalid_cwd(sh, cwd, user_path, logical_pwd));
	update_pwds_vars(sh, cwd, trimmed);
	free(trimmed);
	return (0);
}

int	cd_case_invalid_chdir(t_shell *sh, char *cwd, char *user_path,
		char *logical_pwd)
{
	if (!cwd || !user_path)
		return (ms_err("cd: ", sh->input_args[1], NO_FILE_OR_DIR, 127));
	logical_pwd = apply_logical_cd(cwd, user_path);
	if (!logical_pwd)
		return (1);
	update_pwds_vars(sh, cwd, logical_pwd);
	free(logical_pwd);
	return (0);
}

int	cd_case_invalid_cwd(t_shell *sh, char *cwd, char *user_path,
		char *logical_pwd)
{
	logical_pwd = apply_logical_cd(cwd, user_path);
	if (!logical_pwd)
		return (1);
	update_pwds_vars(sh, cwd, logical_pwd);
	free(logical_pwd);
	return (0);
}

void	update_pwds_vars(t_shell *sh, char *prev_cwd, char *new_pwd)
{
	char	*joined_pwd;
	char	*joined_old_pwd;
	char	**split_pwd;
	char	**split_old_pwd;

	joined_pwd = ft_strjoin("PWD=", new_pwd);
	if (!joined_pwd)
		return ;
	split_pwd = ft_split(joined_pwd, '=');
	free(joined_pwd);
	if (!split_pwd)
		return ;
	update_pwd_var(sh, split_pwd, "PWD");
	joined_old_pwd = ft_strjoin("OLDPWD=", prev_cwd);
	if (!joined_old_pwd)
		return ;
	split_old_pwd = ft_split(joined_old_pwd, '=');
	free(joined_old_pwd);
	if (!split_old_pwd)
		return ;
	update_pwd_var(sh, split_old_pwd, "OLDPWD");
}

void	update_pwd_var(t_shell *sh, char **split_pwd, char *key)
{
	t_list	*pwd_var;

	pwd_var = ft_getenv(key, &sh->this_env);
	if (pwd_var != NULL)
		ft_update_env_value(pwd_var, split_pwd);
	else
		add_new_env_var(sh, split_pwd);
}

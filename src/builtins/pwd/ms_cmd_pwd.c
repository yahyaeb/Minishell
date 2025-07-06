/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:03:51 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/16 10:01:04 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	cmd_pwd(t_shell *sh)
{
	char	*cwd;
	t_list	*pwd;

	cwd = store_cwd(NULL);
	if (cwd != NULL)
	{
		printf("%s\n", cwd);
		free(cwd);
		return (0);
	}
	pwd = ft_getenv("PWD", &sh->this_env);
	if (pwd && ((char **)pwd->content)[1])
	{
		printf("%s\n", ((char **)pwd->content)[1]);
		return (0);
	}
	return (ms_err("pwd", NO_CUR_DIR, NO_ACC_PAR, 1));
}

char	*store_cwd(char *cwd)
{
	cwd = getcwd(NULL, 0);
	if (!cwd)
		return (NULL);
	return (cwd);
}

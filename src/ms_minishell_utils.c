/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_minishell_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 11:40:20 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/15 10:09:29 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	validate_direct_path(char **argv, t_shell *sh)
{
	struct stat	st;

	if (access(argv[0], F_OK) != 0)
	{
		sh->last_exit_status = ms_err("", argv[0], NO_FILE_OR_DIR, 127);
		return (1);
	}
	if (stat(argv[0], &st) != 0)
	{
		sh->last_exit_status = ms_err("", argv[0], NO_FILE_OR_DIR, 127);
		return (1);
	}
	if (S_ISDIR(st.st_mode))
	{
		sh->last_exit_status = ms_err("", argv[0], CMD_IS_DIR, 126);
		return (1);
	}
	if (access(argv[0], X_OK) != 0)
	{
		sh->last_exit_status = ms_err("", argv[0], PERM_DENY, 126);
		return (1);
	}
	return (0);
}

int	validate_in_path(char **argv, char **envp, t_shell *sh)
{
	char	*cmd_path;

	cmd_path = get_cmd_path(argv[0], envp);
	if (!cmd_path)
	{
		sh->last_exit_status = ms_err("", argv[0], CMD_NOT_FOUND, 127);
		return (1);
	}
	free(cmd_path);
	return (0);
}

int	cmd_echo_x(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		printf("%s", argv[i]);
		if (argv[i + 1])
			printf(" ");
		i++;
	}
	printf("\n");
	return (0);
}

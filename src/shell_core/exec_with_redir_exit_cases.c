/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_with_redir_exit_cases.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 18:43:29 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/11 19:53:23 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	exec_echo_case(t_shell *sh, char **argv)
{
	int	res;

	sh->input_args = argv;
	res = cmd_echo(sh);
	free_memory(sh);
	return (res);
}

int	exec_cmd(t_shell *sh, char *cmd_path, char **env, char **argv)
{
	execve(cmd_path, argv, env);
	perror("execve failed");
	free(cmd_path);
	free_memory(sh);
	return (0);
}

void	exec_redir_cmd(t_pipeline *cmd, char **env, t_shell *sh)
{
	if (cmd->cmd_count < 1)
	{
		free_args(sh->input_args);
		exit(0);
	}
	free_args(sh->input_args);
	execute_command(cmd, env, sh);
}

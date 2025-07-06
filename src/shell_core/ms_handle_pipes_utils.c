/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_handle_pipes_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 15:19:08 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/11 19:46:05 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

bool	validate_cd_command(char **argv, t_shell *sh)
{
	struct stat	st;

	if (!argv[1])
	{
		ft_putstr_fd(" cd: missing argument\n", 2);
		sh->last_exit_status = 1;
		return (false);
	}
	if (stat(argv[1], &st) != 0)
	{
		ft_putstr_fd(" cd: No such file or directory\n", 2);
		sh->last_exit_status = 1;
		return (false);
	}
	if (!S_ISDIR(st.st_mode))
	{
		ft_putstr_fd(" cd: Not a directory\n", 2);
		sh->last_exit_status = 1;
		return (false);
	}
	return (true);
}

bool	validate_pipeline_commands(t_pipeline *p, t_shell *sh)
{
	int			i;
	char		**argv;

	i = 0;
	while (i < p->cmd_count)
	{
		argv = p->cmds[i].argv;
		if (!argv || !argv[0])
			continue ;
		if (strcmp(argv[0], "cd") == 0)
		{
			if (!validate_cd_command(argv, sh))
				return (false);
		}
		i++;
	}
	return (true);
}

int	validate_all_non_builtins(t_pipeline *p, char **env, t_shell *sh)
{
	int		j;
	char	*cmd_path;

	j = 0;
	while (j < p->cmd_count)
	{
		if (!is_builtin(p->cmds[j].argv[0]))
		{
			cmd_path = get_cmd_path(p->cmds[j].argv[0], env);
			if (!cmd_path)
			{
				sh->last_exit_status = ms_err("",
						p->cmds[j].argv[0], CMD_NOT_FOUND, 127);
				return (0);
			}
			free(cmd_path);
		}
		j++;
	}
	return (1);
}

void	open_pipe_if_needed(int i, int cmd_count, int pipe_fd[2])
{
	if (i < cmd_count - 1)
	{
		if (pipe(pipe_fd) < 0)
		{
			perror("pipe");
			exit(EXIT_FAILURE);
		}
	}
}

// void	handle_cat_no_args(t_commands *cmd, int i, int total)
// {
// 	int	dev_null;

// 	if (strcmp(cmd->argv[0], "cat") == 0 && !cmd->argv[1])
// 	{
// 		// signal(SIGPIPE, SIG_IGN);
// 		if (i < total - 1)
// 		{
// 			dev_null = open("/dev/null", O_WRONLY);
// 			if (dev_null != -1)
// 			{
// 				// dup2(dev_null, STDOUT_FILENO);
// 				// dup2(dev_null, STDERR_FILENO);
// 				close(dev_null);
// 			}
// 		}
// 	}
// }

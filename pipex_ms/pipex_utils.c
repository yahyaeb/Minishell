/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:55:38 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/11 12:30:05 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	handle_bonus(t_pipex *pipex, int argc, char **argv, int cmd_count)
{
	int	i;

	i = 0;
	ft_init_pipex(pipex, argv[1], argv[argc - 1]);
	pipex->cmd_count = cmd_count;
	if (ft_strcmp(argv[argc - 1], "/dev/stdout") == 0)
		pipex->out_fd = STDOUT_FILENO;
	else
		setup_outfd(pipex, argv, argc);
	pipex->cmd_args = malloc(sizeof(char **) * pipex->cmd_count);
	if (!pipex->cmd_args)
		ft_exit_error(pipex, "malloc failed");
	while (i < pipex->cmd_count)
	{
		pipex->cmd_args[i] = ft_split(argv[i + 3], ' ');
		if (!pipex->cmd_args[i] || !pipex->cmd_args[i][0])
			ft_exit_error(pipex, "command not found");
		i++;
	}
	ft_parse_paths(pipex);
	execute_multiple_cmds(pipex);
	free_pipex(pipex);
}

void	fork_and_run(t_pipex *pipex, int i, int prev_fd, int *pipefd)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		ft_exit_error(pipex, "fork error");
	if (pid == 0)
	{
		if (i == pipex->cmd_count - 1)
			execute_child(pipex, prev_fd, pipex->out_fd, pipex->cmd_args[i]);
		else
			execute_child(pipex, prev_fd, pipefd[1], pipex->cmd_args[i]);
	}
}

void	execute_all_children(t_pipex *pipex)
{
	int		i;
	int		pipefd[2];
	int		prev_fd;

	i = 0;
	prev_fd = pipex->in_fd;
	while (i < pipex->cmd_count)
	{
		if (i < pipex->cmd_count - 1 && pipe(pipefd) == -1)
			ft_exit_error(pipex, "pipe error");
		fork_and_run(pipex, i, prev_fd, pipefd);
		if (prev_fd != pipex->in_fd)
			close(prev_fd);
		if (i < pipex->cmd_count - 1)
		{
			close(pipefd[1]);
			prev_fd = pipefd[0];
		}
		i++;
	}
}

void	ft_execute_pipex(t_pipex *pipex)
{
	int		pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (pipe(pipefd) == -1)
		ft_exit_error(pipex, "pipe failed");
	pid1 = fork();
	if (pid1 == -1)
		ft_exit_error(pipex, "fork failed");
	if (pid1 == 0)
		execute_first_child(pipex, pipefd);
	pid2 = fork();
	if (pid2 == -1)
		ft_exit_error(pipex, "fork failed");
	if (pid2 == 0)
		execute_second_child(pipex, pipefd);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, &status, 0);
	pipex->exit_status = WEXITSTATUS(status);
}

void	handle_mandatory(t_pipex *pipex, char **argv, int argc)
{
	ft_init_pipex(pipex, argv[1], argv[argc - 1]);
	ft_parse_cmds(pipex, argv);
	ft_parse_paths(pipex);
	ft_execute_pipex(pipex);
	free_pipex(pipex);
}

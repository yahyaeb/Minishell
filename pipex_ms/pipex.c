/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:55:38 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/17 04:37:38 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_child(t_pipex *pipex, int in_fd, int out_fd, char **cmd)
{
	char	*cmd_path;

	if (dup2(in_fd, STDIN_FILENO) == -1 || dup2(out_fd, STDOUT_FILENO) == -1)
		ft_exit_error(pipex, "dup2 error");
	cmd_path = find_cmd_path(cmd[0], pipex->cmd_paths);
	if (!cmd_path)
	{
		ft_printf("%s: command not found\n", cmd[0]);
		free_pipex(pipex);
		exit(127);
	}
	execve(cmd_path, cmd, pipex->envp);
	perror("execve");
	free(cmd_path);
	exit(1);
}

static void	free_argv(char **argv, int size)
{
	int	i;

	i = 0;
	while (i < size)
		free(argv[i++]);
	free(argv);
}

static int	validate_pipeline(t_pipeline *pipeline)
{
	if (!pipeline || !pipeline->cmds->infile)
	{
		perror("Invalid pipeline");
		return (1);
	}
	if (ft_strcmp(pipeline->cmds->infile, "here_doc") != 0)
	{
		perror("here_doc");
		return (1);
	}
	return (0);
}

static char	**build_pipex_argv(t_pipeline *pipeline, int *argc)
{
	char	**argv;
	int		k;
	int		i;

	i = 0;
	k = 0;
	*argc = 4 + pipeline->cmd_count;
	argv = malloc(sizeof(char *) * (*argc + 1));
	if (!argv)
		return (perror("malloc"), NULL);
	argv[k++] = ft_strdup("pipex");
	argv[k++] = ft_strdup("here_doc");
	argv[k++] = ft_strdup(pipeline->cmds->limiter);
	while (i < pipeline->cmd_count)
	{
		if (!pipeline->cmds[i].argv)
			return (free_argv(argv, k), NULL);
		argv[k++] = join_args(pipeline->cmds[i++].argv);
	}
	if (pipeline->cmds[pipeline->cmd_count - 1].outfile)
		argv[k++] = ft_strdup(pipeline->cmds[pipeline->cmd_count - 1].outfile);
	else
		argv[k++] = ft_strdup("/dev/stdout");
	argv[k] = NULL;
	return (argv);
}

int	run_pipex_from_minshell(t_pipeline *pipeline, char **envp, int exit_status)
{
	t_pipex	pipex;
	char	**argv;
	int		argc;

	memset(&pipex, 0, sizeof(pipex));
	if (validate_pipeline(pipeline))
		return (1);
	init_pipex(&pipex, envp);
	if (handle_heredoc(pipeline->cmds->limiter, exit_status) != 0)
		pipex_error_heredoc("Error: here_doc failed", 1);
	free(pipeline->cmds->infile);
	pipeline->cmds->infile = strdup(".heredoc_tmp");
	pipex.in_fd = open(".heredoc_tmp", O_RDONLY);
	if (pipex.in_fd < 0)
		pipex_error_heredoc("open .heredoc_tmp", 1);
	if (pipex.out_fd < 0)
		pipex.out_fd = STDOUT_FILENO;
	argv = build_pipex_argv(pipeline, &argc);
	if (!argv)
		return (1);
	handle_bonus(&pipex, argc, argv, pipeline->cmd_count);
	free_argv(argv, argc);
	return (pipex.exit_status);
}

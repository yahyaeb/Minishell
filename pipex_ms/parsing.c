/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:55:38 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/11 12:36:58 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_cmd_path(char *cmd, char **paths)
{
	int			i;
	char		*temp;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], cmd);
		if (!temp)
			return (NULL);
		if (access(temp, X_OK) == 0)
			return (temp);
		free(temp);
		i++;
	}
	return (NULL);
}

char	*get_path_from_env(char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

void	ft_parse_cmds(t_pipex *pipex, char **argv)
{
	int	i;

	i = 0;
	pipex->cmd_count = 2;
	pipex->cmd_args = malloc(sizeof(char **) * pipex->cmd_count);
	if (!pipex->cmd_args)
		ft_exit_error(pipex, "malloc failed");
	while (i < pipex->cmd_count)
	{
		pipex->cmd_args[i] = ft_split(argv[i + 2], ' ');
		if (!pipex->cmd_args[i] || !pipex->cmd_args[i][0])
		{
			if (pipex->cmd_args[i])
				ft_free_array(pipex->cmd_args[i], -1);
			ft_printf("pipex: command not found\n");
			while (--i >= 0)
				ft_free_array(pipex->cmd_args[i], -1);
			free(pipex->cmd_args);
			exit(127);
		}
		i++;
	}
}

void	ft_parse_paths(t_pipex *pipex)
{
	int			j;
	char		*path_value;
	char		*temp;

	j = 0;
	path_value = get_path_from_env(pipex->envp);
	if (!path_value)
		ft_exit_error(pipex, "PATH not found");
	pipex->cmd_paths = ft_split(path_value, ':');
	if (!pipex->cmd_paths)
		ft_exit_error(pipex, "Failed to split PATH");
	while (pipex->cmd_paths[j])
	{
		temp = ft_strjoin(pipex->cmd_paths[j], "/");
		free(pipex->cmd_paths[j]);
		pipex->cmd_paths[j] = temp;
		j++;
	}
}

void	handle_here_doc(t_pipex *pipex, int argc, char **argv)
{
	char	*limiter;

	pipex->here_doc = true;
	limiter = argv[2];
	read_heredoc_input(pipex, limiter);
	setup_here_doc_fds(pipex, argv[argc - 1]);
	parse_here_doc_commands(pipex, argc, argv);
	ft_parse_paths(pipex);
	execute_multiple_cmds(pipex);
	unlink(".heredoc_tmp");
	free_pipex(pipex);
}

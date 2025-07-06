/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_with_redir_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 11:29:54 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/05 12:52:09 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*get_cmd_path(char *cmd, char **envp)
{
	char	*path_str;
	char	**paths;
	char	*full_path;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	path_str = get_path_from_env(envp);
	if (!path_str)
		return (NULL);
	paths = ft_split(path_str, ':');
	if (!paths)
		return (NULL);
	full_path = shell_find_cmd_path(cmd, paths);
	ft_free_array(paths, -1);
	return (full_path);
}

int	open_fd(const char *filename, int flags, t_shell *sh)
{
	int	fd;

	fd = open(filename, flags, 0644);
	if (fd < 0)
	{
		sh->last_exit_status = 1;
		perror(filename);
		return (-1);
	}
	return (fd);
}

int	get_output_flags(int append)
{
	int	flags;

	flags = O_WRONLY | O_CREAT;
	if (append)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	return (flags);
}

void	close_fds(int in, int out)
{
	if (in != -1)
		close(in);
	if (out != -1)
		close(out);
}

char	*get_cmd_path_from_list(char *cmd, t_list *env_list)
{
	char	*path_str;
	char	**paths;
	char	*full_path;
	t_list	*path_node;

	if (ft_strchr(cmd, '/'))
	{
		if (access(cmd, X_OK) == 0)
			return (ft_strdup(cmd));
		else
			return (NULL);
	}
	path_node = ft_getenv("PATH", &env_list);
	if (!path_node)
		return (NULL);
	path_str = ((char **)path_node->content)[1];
	if (!path_str)
		return (NULL);
	paths = ft_split(path_str, ':');
	if (!paths)
		return (NULL);
	full_path = shell_find_cmd_path(cmd, paths);
	ft_free_array(paths, -1);
	return (full_path);
}

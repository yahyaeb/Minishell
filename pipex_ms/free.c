/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:55:38 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/11 13:02:17 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exit_error(t_pipex *pipex, const char *msg)
{
	perror(msg);
	free_pipex(pipex);
	exit(EXIT_FAILURE);
}

void	ft_free_array(char **arr, int count)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	if (count == -1)
	{
		while (arr[i])
			free(arr[i++]);
	}
	else
	{
		while (i < count)
			free(arr[i++]);
	}
	free(arr);
}

void	ft_free_2d_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_pipex(t_pipex *pipex)
{
	int	i;

	if (!pipex)
		return ;
	if (pipex->cmd_args)
	{
		i = 0;
		while (i < pipex->cmd_count)
		{
			if (pipex->cmd_args[i])
				ft_free_2d_array(pipex->cmd_args[i]);
			i++;
		}
		free(pipex->cmd_args);
	}
	if (pipex->cmd_paths)
		ft_free_2d_array(pipex->cmd_paths);
	if (pipex->in_fd != -1)
		close(pipex->in_fd);
	if (pipex->out_fd != -1 && pipex->out_fd != STDOUT_FILENO)
		close(pipex->out_fd);
}

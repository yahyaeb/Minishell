/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:55:38 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/17 17:36:34 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_heredoc(const char *limiter, int exit_status)
{
	char	*line;
	int		fd;
	int		res;

	res = 0;
	line = NULL;
	fd = open_heredoc_file();
	if (fd < 0)
		return (1);
	while (1)
	{
		res = heredoc_loop(line, limiter, fd, exit_status);
		if (res == 1)
			return (1);
		else if (res == 2)
			break ;
	}
	free_line_and_close_fd(line, fd);
	return (0);
}

char	*join_args(char **args)
{
	int		i;
	size_t	total_len;
	char	*result;

	if (!args || !args[0])
		return (strdup(""));
	i = 0;
	total_len = total_args_length(args);
	if (total_len == 0)
		return (strdup(""));
	if (!allocate_mem(&result, total_len))
		return (NULL);
	result[0] = '\0';
	i = 0;
	while (args[i])
	{
		ft_strlcat(result, args[i], total_len + 1);
		if (args[i + 1])
			ft_strlcat(result, " ", total_len + 1);
		i++;
	}
	return (result);
}

int	allocate_mem(char **str, int length)
{
	*str = malloc(length);
	if (!*str)
		return (0);
	return (1);
}

size_t	total_args_length(char **args)
{
	size_t	total;
	int		i;

	i = 0;
	total = 0;
	while (args[i])
		total += ft_strlen(args[i++]) + 1;
	return (total);
}

void	init_pipex(t_pipex *pipex, char **envp)
{
	memset(pipex, 0, sizeof(t_pipex));
	pipex->envp = envp;
	pipex->here_doc = true;
	pipex->in_fd = -1;
	pipex->out_fd = -1;
}

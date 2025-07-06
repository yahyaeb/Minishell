/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:39:19 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/06 21:50:53 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Read a line with ft_gnl and return 0. 
 * In case of error, close fd, display error_msg and return -1.
 * If the error_msg is "no", close fd and return 1.
 */
int	ft_read_line(int fd, char **line, char *error_msg)
{
	*line = ft_gnl(fd);
	if (*line == NULL)
	{
		if (ft_strncmp(error_msg, "no", 2) != 0)
		{
			perror(error_msg);
			close(fd);
			return (-1);
		}
		close(fd);
		return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 21:20:52 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/06 21:38:50 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Try to open the file at fpath.
 * In case of error returned by open, display error_msg.
 * Else, return fd.
 * Access modes supported: O_RDONLY, O_WRONLY, O_RDWR.
 *
 * Example:
 *
 * file = ft_open_file(fpath, "O_RDONLY", "Error\nError opening file\n");
 *      if (file == -1)
 *              return (1);
 *
 */
int	ft_open_file(char *fpath, char *access_mode, char *error_msg)
{
	int	file;

	file = -1;
	if (ft_strncmp(access_mode, "O_RDONLY", ft_strlen("O_RDONLY")) == 0)
		file = open(fpath, O_RDONLY);
	else if (ft_strncmp(access_mode, "O_WRONLY", ft_strlen("O_WRONLY")) == 0)
		file = open(fpath, O_WRONLY);
	else if (ft_strncmp(access_mode, "O_RDWR", ft_strlen("O_RDWR")) == 0)
		file = open(fpath, O_RDWR);
	if (file == -1)
	{
		perror(error_msg);
		return (-1);
	}
	return (file);
}

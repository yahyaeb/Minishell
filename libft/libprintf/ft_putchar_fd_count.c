/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_count.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:22:43 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/19 11:32:05 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * This version of ft_putchar_fd writes a single character to a specified
 * file director, but also returns the number of bytes written.
 *
*/

size_t	ft_putchar_fd_count(char c, int fd)
{
	write(fd, &c, 1);
	return (1);
}

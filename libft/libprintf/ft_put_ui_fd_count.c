/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ui_fd_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:22:43 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/19 11:34:27 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * This version of ft_putnbr_fd writes an unsigned int to a specified
 * file director, but also returns the number of bytes written.
 * It was designed to handle an unsigned int when ft_put_ui_fd_count cannot.
*/

size_t	ft_put_ui_fd_count(unsigned int n, int fd)
{
	size_t	i;

	i = 0;
	if (n == 0)
	{
		i += ft_putchar_fd_count('0', fd);
		return (i);
	}
	if (n > 9)
	{
		i += ft_putnbr_fd_count(n / 10, fd);
	}
	i += ft_putchar_fd_count((n % 10) + '0', fd);
	return (i);
}

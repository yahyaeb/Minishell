/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_count.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:22:43 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/19 11:34:27 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * This version of ft_putnbr_fd writes an integer to a specified
 * file director, but also returns the number of bytes written.
 *
*/

size_t	ft_putnbr_fd_count(int n, int fd)
{
	size_t	i;

	i = 0;
	if (n == -2147483648)
	{
		i += ft_putstr_fd_count("-2147483648", fd);
		return (i);
	}
	if (n < 0)
	{
		i += ft_putchar_fd_count('-', fd);
		n = -n;
	}
	if (n > 9)
	{
		i += ft_putnbr_fd_count(n / 10, fd);
	}
	i += ft_putchar_fd_count((n % 10) + '0', fd);
	return (i);
}

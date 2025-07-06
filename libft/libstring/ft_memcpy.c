/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:34:51 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:31:05 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Implementation of memcpy() from <string.h>:
 * Copies a specified number of bytes from one memory location to another.
 */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*dest_p;
	char	*src_p;

	if (dest == NULL && src == NULL)
	{
		return (NULL);
	}
	dest_p = (char *)dest;
	src_p = (char *)src;
	while (n > 0)
	{
		*dest_p = *src_p;
		dest_p++;
		src_p++;
		n--;
	}
	return (dest);
}

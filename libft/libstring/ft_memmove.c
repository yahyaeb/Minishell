/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:35:00 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:31:13 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 *Implementation of memmove() from <string.h>: Copies a specified number of 
 bytes from one memory location to another. Handles overlapping memory regions.
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_uc;
	const unsigned char	*src_uc;

	if (dest == src || n == 0)
		return (dest);
	dest_uc = (unsigned char *)dest;
	src_uc = (const unsigned char *)src;
	if (dest_uc < src_uc)
	{
		while (n--)
			*dest_uc++ = *src_uc++;
	}
	else
	{
		dest_uc += n;
		src_uc += n;
		while (n--)
			*(--dest_uc) = *(--src_uc);
	}
	return (dest);
}

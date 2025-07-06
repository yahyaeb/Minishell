/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:34:37 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:30:57 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Implementation of memcmp() from <string.h>: Compares two blocks of memory
 * byte by byte, up to a specified number of bytes.
 */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_p;
	const unsigned char	*s2_p;

	s1_p = s1;
	s2_p = s2;
	while (n > 0)
	{
		if (*s1_p != *s2_p)
		{
			return ((unsigned char)*s1_p - (unsigned char)*s2_p);
		}
		s1_p++;
		s2_p++;
		n--;
	}
	return (0);
}

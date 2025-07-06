/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:35:09 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:31:20 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Implementation of memset() from <string.h>: Fills a block of memory 
 * with a specified value.
 */

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*s_p;

	s_p = (unsigned char *)s;
	while (n > 0)
	{
		*s_p = (unsigned char)c;
		s_p++;
		n--;
	}
	return (s);
}

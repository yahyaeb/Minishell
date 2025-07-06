/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:33:40 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:27:39 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Implementation of bzero() from <string.h>: Sets a block of memory to zero 
 * (equivalent to memset(ptr, 0, n)).
 */
void	ft_bzero(void *s, size_t n)
{
	char	*s_p;

	s_p = (char *)s;
	while (n > 0)
	{
		*s_p = '\0';
		s_p++;
		n--;
	}
}

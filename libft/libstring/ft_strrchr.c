/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:02:51 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:33:32 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Implementation of strrchr() from <string.h>: Searches for the last 
 * occurrence of a character in a string.
 */
char	*ft_strrchr(const char *s, int c)
{
	const char	*last_char_found = NULL;

	if (c < 0 || c > 255)
		c = c % 256;
	while (*s)
	{
		if ((unsigned char)*s == (unsigned char)c)
		{
			last_char_found = s;
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return ((char *)last_char_found);
}

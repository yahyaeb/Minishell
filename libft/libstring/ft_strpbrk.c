/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:12:26 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/02 11:27:51 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Implementation of strpbrk() from <string.h>: Locates the first occurence
 * in the string s of any of the bytes in the string accept.
 */
char	*ft_strpbrk(const char *s, const char *accept)
{
	int	i;

	i = 0;
	if (s != NULL && accept != NULL)
	{
		while (*s)
		{
			i = 0;
			while (accept[i])
			{
				if (*s == accept[i])
					return ((char *)s);
				i++;
			}
			s++;
		}
	}
	return (NULL);
}

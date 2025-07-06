/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnopbrk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 10:12:26 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/02 12:26:23 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Reverses the functionality of strpbrk() from <string.h>: Locates the first
 * occurence in the string s of any of the bytes NOT in the string accept.
 */
char	*ft_strnopbrk(const char *s, const char *accept)
{
	int	i;
	int	found;

	if (s != NULL && accept != NULL)
	{
		while (*s)
		{
			i = 0;
			found = 0;
			while (accept[i])
			{
				if (*s == accept[i])
				{
					found = 1;
					break ;
				}
				i++;
			}
			if (found == 0)
				return ((char *)s);
			s++;
		}
	}
	return (NULL);
}

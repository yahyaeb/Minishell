/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:35:29 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:32:18 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Implementation of strdup() from <string.h>: Allocates memory and copies a 
 * string into it, returning a pointer to the new string.
 */
char	*ft_strdup(const char *s)
{
	char	*dup;
	char	*dup_start;
	size_t	len;

	len = ft_strlen(s);
	dup = malloc(len + 1);
	if (dup == NULL)
		return (NULL);
	dup_start = dup;
	while (*s)
	{
		*dup = *s;
		dup++;
		s++;
	}
	*dup = '\0';
	return (dup_start);
}

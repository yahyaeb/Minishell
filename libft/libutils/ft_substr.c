/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:57:04 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:33:47 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Extracts a substring from a given string, starting from a specified index 
 * and up to a specified length.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*substring;
	unsigned int		s_len;
	size_t				i;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	if (start >= s_len)
		len = 0;
	else if (start + len > s_len)
		len = s_len - start;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (substring == NULL)
		return (NULL);
	if (len > 0)
	{
		while (i < len)
		{
			substring[i] = s[start + i];
			i++;
		}
	}
	substring[i] = '\0';
	return (substring);
}

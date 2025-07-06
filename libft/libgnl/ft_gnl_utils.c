/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:36:54 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/19 09:37:21 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

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

char	*ft_strchr(const char *s, int c)
{
	if (c < 0 || c > 255)
		c = c % 256;
	while (*s)
	{
		if (*s == (char)c)
		{
			return ((char *)s);
		}
		s++;
	}
	if (c == '\0')
	{
		return ((char *)s);
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	const char	*str;

	str = s;
	while (*str)
	{
		str++;
	}
	return (str - s);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (size == 1)
	{
		dest[0] = '\0';
		return (src_len);
	}
	i = 0;
	while ((i < size - 1) && (src[i] != '\0'))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_len);
}

void	clean_stash(char **stash)
{
	free(*stash);
	*stash = NULL;
}

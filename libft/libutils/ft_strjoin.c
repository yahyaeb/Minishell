/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:57:17 by mmalie            #+#    #+#             */
/*   Updated: 2025/05/08 21:22:44 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Implementation of strjoin() from <string.h>: Concatenates two strings 
 * into a newly allocated string.
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined_str;
	size_t	len;

	len = ft_strlen(s1) + ft_strlen(s2);
	joined_str = (char *)malloc(sizeof(char) * (len + 1));
	if (joined_str == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(joined_str, s1, len + 1);
	ft_strlcat(joined_str, s2, len + 1);
	return (joined_str);
}

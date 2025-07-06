/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:35:47 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:33:00 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Implementation of strlen() from <string.h>: Returns the length 
 * of the given string (excluding the null terminator).
*/
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

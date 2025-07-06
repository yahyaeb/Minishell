/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:35:29 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:32:18 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Allocates memory for a new string and initializes it with null characters.
 */
char	*ft_strnew(size_t size)
{
	char	*fresh_str;
	size_t	i;

	fresh_str = (char *)malloc(size + 1);
	if (fresh_str == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (i <= size)
	{
		fresh_str[i] = '\0';
		i++;
	}
	return (fresh_str);
}

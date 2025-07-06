/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:46:19 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:27:49 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Implementation of calloc() from <stdlib.h>: Allocates memory for an array 
 * of elements and initializes all bytes to zero.
 */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	size_t	arr_size;

	if (nmemb == 0 || size == 0)
	{
		arr_size = 0;
	}
	else if (nmemb > (SIZE_MAX / size))
	{
		return (NULL);
	}
	else
	{
		arr_size = (nmemb * size);
	}
	array = malloc(arr_size);
	if (array == NULL)
	{
		return (NULL);
	}
	if (arr_size > 0)
	{
		ft_memset(array, 0, arr_size);
	}
	return (array);
}

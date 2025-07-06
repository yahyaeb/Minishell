/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_arr_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:45:25 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/05 11:00:45 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Copy size elements of a src array of ints to a dest array of ints.
 */
void	ft_cpy_arr_int(int *dst_arr, int *src_arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		dst_arr[i] = src_arr[i];
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_arr_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 10:42:26 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/05 10:44:58 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Reverse an array of int in place.
 */
void	ft_rev_arr_int(int *arr, size_t size)
{
	size_t	i;
	size_t	middle;

	i = 0;
	middle = (size / 2);
	while (i < middle)
	{
		ft_swap_ints(&arr[i], &arr[size - 1 - i]);
		i++;
	}
	return ;
}

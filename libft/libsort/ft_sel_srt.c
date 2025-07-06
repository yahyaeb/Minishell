/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sel_srt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:45:21 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/03 23:21:59 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * SELECTION SORT works by selecting the smallest (or largest) element and
 * swapping it into its correct position in each iteration.
 *
 * STEPS:
 * - Find the smallest (or largest) element and swap it with the first element. 
 * - Find the new smallest (or largest) among remaining elements.
 * - Continue until all elements are moved to correct position.
 *
 * OPTIONS: 'a' for 'a'scending order. 'd' for 'd'escending order.
 */

void	ft_sel_srt(int *arr, size_t size, char opt)
{
	size_t	i;
	size_t	j;
	size_t	pinned_i;

	if (size <= 1)
		return ;
	i = 0;
	while (i < size)
	{
		pinned_i = i;
		j = i + 1;
		while (j < size)
		{
			if ((opt == 'a' && arr[j] < arr[pinned_i])
				|| (opt == 'd' && arr[j] > arr[pinned_i]))
				pinned_i = j;
			j++;
		}
		ft_swap_ints(&arr[i], &arr[pinned_i]);
		i++;
	}
	return ;
}

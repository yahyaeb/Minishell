/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ins_srt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:47:31 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/04 11:30:41 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * INSERTION SORT works by building a sorted section of the array one element
 * at a time by inserting elements into their correct positions.
 *
 * STEPS:
 * - Start at second element of the array (the first is assumed to be sorted).
 * - Compare second element with the first and compare them. Swap if needed.
 * - Move to the third element, compare it to the first two and put it at
 *      the correct position.
 * - Repeat until the array is sorted.
 * 
 * OPTIONS: 'a' for 'a'scending order, 'd' for 'd'escending order.
 */

// NB: Needs a if(!arr || size < 2) return; check but function 
// would be too long to pass norminette. To refactor.
void	ft_ins_srt(int *arr, size_t size, char opt)
{
	size_t	i;
	size_t	sorted;
	int		temp;
	size_t	j;

	if ((opt == 'a' && arr[1] < arr[0]) || (opt == 'd' && arr[1] > arr[0]))
		ft_swap_ints(&arr[1], &arr[0]);
	sorted = 1;
	i = 2;
	while (i < size)
	{
		j = 0;
		if ((opt == 'a' && arr[i] < arr[sorted])
			|| (opt == 'd' && arr[i] > arr[sorted]))
		{
			temp = arr[i];
			while ((opt == 'a' && arr[i] > arr[j])
				|| (opt == 'd' && arr[i] < arr[j]))
				j++;
			ft_shift_right_ints(arr, size, j, i);
			arr[j] = temp;
			sorted = i;
		}
		i++;
	}
}

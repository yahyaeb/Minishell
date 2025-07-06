/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bub_srt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 22:20:47 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/04 00:08:24 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * BUBBLE SORT works by repeatedly swapping adjacent elements if they are in
 * the wrong order.
 *
 * STEPS:
 * - Iterate through the array, processing each element one by one.
 * - For each element, compare it with the one following it.
 * - If the current element is greater than the next, swap them so that the
 *   larger value is positioned at the end.
 * - Repeat for as many times as there are elements in the array.
 *
 * OPTIONS: 'a' for 'a'scending order, 'd' for 'd'escending order.
 */
/* 
void	bubble_sort(void *arr, size_t size, size_t elem_size, 
                     int (*cmp)(const void *, const void *));
int	int_cmp(const void *a, const void *b);
int	str_cmp(const void *a, const void *b);
*/
void	ft_bub_srt(int *arr, size_t size, char opt)
{
	size_t	i;
	int		swapped;

	if (size <= 1)
		return ;
	swapped = 1;
	while (swapped)
	{
		swapped = 0;
		i = 0;
		while (i < (size - 1))
		{
			if ((opt == 'a' && arr[i] > arr[i + 1])
				|| (opt == 'd' && arr[i] < arr[i + 1]))
			{
				ft_swap_ints(&arr[i], &arr[i + 1]);
				swapped = 1;
			}
			i++;
		}
		size--;
	}
	return ;
}

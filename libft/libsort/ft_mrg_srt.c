/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mrg_srt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:49:56 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/06 22:14:10 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * MERGE SORT is a divide_and_conquer algorithm that recursively divides the
 * array into halves and merges them in sorted order.
 *
 * STEPS:
 * - Divide the array recursively into two halves while possible.
 * - Conquer: sort each subarray individually using the merg sort algorithm.
 * - Merge: merge back the sorted subarrays together in sorted order until
 *       all elements have been merged.
 *
 * NB: ft_mrg_arrs and ft_mrg_arrs_rev could be merged in one single function
 *     taking an option 'a'scending or 'd'escending order. But it would require
 *     a struct (the Norm allows up to 4 parameters maximum).
 *
 */

void	ft_mrg_arrs(int *arr, int *left_sub, int *right_sub, size_t size);
void	ft_mrg_arrs_rev(int *arr, int *left_sub, int *right_sub, size_t size);
void	ft_cpy_arr_int(int *dst_arr, int *src_arr, size_t size);

void	ft_mrg_srt(int *arr, size_t size, char opt)
{
	size_t	middle;
	int		*left_sub;
	int		*right_sub;

	if (size < 2)
		return ;
	middle = size / 2;
	left_sub = ft_calloc(middle, sizeof(int));
	right_sub = ft_calloc(size - middle, sizeof(int));
	if (!left_sub || !right_sub)
		return ;
	ft_cpy_arr_int(&left_sub[0], &arr[0], middle);
	ft_cpy_arr_int(&right_sub[0], &arr[middle], size - middle);
	ft_mrg_srt(left_sub, middle, opt);
	ft_mrg_srt(right_sub, size - middle, opt);
	if (opt == 'd')
		ft_mrg_arrs_rev(arr, left_sub, right_sub, size);
	else
		ft_mrg_arrs(arr, left_sub, right_sub, size);
	free(left_sub);
	free(right_sub);
	return ;
}

void	ft_mrg_arrs(int *arr, int *left_sub, int *right_sub, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	left_size;
	size_t	right_size;

	i = 0;
	j = 0;
	k = 0;
	left_size = size / 2;
	right_size = size - left_size;
	while (i < left_size && j < right_size)
	{
		if (left_sub[i] <= right_sub[j])
			arr[k++] = left_sub[i++];
		else
			arr[k++] = right_sub[j++];
	}
	while (i < left_size)
		arr[k++] = left_sub[i++];
	while (j < right_size)
		arr[k++] = right_sub[j++];
	return ;
}

void	ft_mrg_arrs_rev(int *arr, int *left_sub, int *right_sub, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	k;
	size_t	left_size;
	size_t	right_size;

	i = 0;
	j = 0;
	k = 0;
	left_size = size / 2;
	right_size = size - left_size;
	while (i < left_size && j < right_size)
	{
		if (left_sub[i] >= right_sub[j])
			arr[k++] = left_sub[i++];
		else
			arr[k++] = right_sub[j++];
	}
	while (i < left_size)
		arr[k++] = left_sub[i++];
	while (j < right_size)
		arr[k++] = right_sub[j++];
	return ;
}

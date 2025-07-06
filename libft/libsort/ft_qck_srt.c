/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qck_srt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 22:51:56 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/05 11:46:43 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * QUICK SORT is a divide-and-conquer algorithm that selects a pivot and
 * partitions the array into smaller sub-arrays.
 *
 * STEPS:
 * - Select a pivot (first, last, random, median...). 
 * - Partition the array around the pivot: put all elements smaller than the
 *      pivot on its left, all greater on its right.The index of the pivot
 *      is thus obtained.
 * - Recursively call the same process to the two subarrays.
 * - Base case: stop when there is only one element left in subarray.
 * - Opts:
 * 	- opts[0]: (order rule) 'a'scending, 'd'escending
 *	- opts[1]: (pivot rule) 'f'irst, 'l'ast, 's'qrt.
 *	- TBD: 'r'andom, 'm'edian
 */
/*
void	ft_quick_sort(int *arr, size_t min, size_t max, char *opts);
size_t	ft_pivot_partition(int *arr, size_t min, size_t max, char *opts);
int	ft_get_pivot(int *arr, size_t min, size_t max, char pivot_rule);
double	ft_sqrt_newton(double number);

void	ft_qck_srt(int *arr, size_t size, char *opts)
{
	if (arr == NULL || size <= 1)
		return ;
	ft_quick_sort(arr, 0, size - 1, opts);
}

void	ft_quick_sort(int *arr, size_t min, size_t max, char *opts)
{
	size_t	pi;

	if (min < max)
	{
		pi = ft_pivot_partition(arr, min, max, opts);
		ft_quick_sort(arr, min, pi - 1, opts);
		ft_quick_sort(arr, pi + 1, max, opts);
	}
}

size_t	ft_pivot_partition(int *arr, size_t min, size_t max, char *opts)
{
	int	pivot;
	size_t	i;
	size_t	j;

	pivot = ft_get_pivot(arr, min, max, opts[1]);
	ft_printf("[ft_pivot_partition] PIVOT: %d\n", pivot);
	i = min;
	j = min + 1;
	while (j <= max)
	{
		if (arr[j] <= pivot)
		{
			i++;
			ft_swap_ints(&arr[i], &arr[j]);
		}
		j++;
	}
	if (i != min)
		ft_swap_ints(&arr[min], &arr[i]);
	return (i);
}

int	ft_get_pivot(int *arr, size_t min, size_t max, char pivot_rule)
{
	int	pivot;

	if (pivot_rule == 'f')
		pivot = arr[min];
	else if (pivot_rule == 'l')
		pivot = arr[max];
	else if (pivot_rule == 's')
		pivot = ft_sqrt_newton(max);
	else
		pivot = ft_sqrt_newton(max);
	return (pivot);
}
*/

/* Get the square root of a number (using Newton method).
 * Return -1 if the number is negative.
 */
/*static double	ft_sqrt_newton(double number)
{
	double	guess;
	double	epsilon;
	double	next_guess;
	double	fabs;

	if (number < 0)
	{
		return (-1);
	}
	guess = number / 2.0;
	epsilon = 0.000001;
	while (1)
	{
		next_guess = (guess + number / guess) / 2.0;
		if ((next_guess - guess) < 0)
			fabs = -(next_guess - guess);
		else
			fabs = (next_guess - guess);
		if (fabs < epsilon)
		{
			return (next_guess);
		}
		guess = next_guess;
	}
}*/

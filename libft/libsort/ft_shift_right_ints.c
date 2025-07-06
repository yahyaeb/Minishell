/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shift_right_ints.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 11:23:02 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/04 11:28:08 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Shift all the ints of an array to the right from given start to given end.
 * The last element will be lost if no copy has been made.
 * Intented to insert later on this element (or another) at arr[start].
 */
void	ft_shift_right_ints(int *arr, size_t size, size_t start, size_t end)
{
	if (!arr || size < 2)
		return ;
	while (end > start)
	{
		arr[end] = arr[end - 1];
		end--;
	}
	return ;
}

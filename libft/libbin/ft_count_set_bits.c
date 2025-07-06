/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_set_bits.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:43:01 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/10 09:06:40 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Counts the number of bits set to 1.
 */
int	ft_count_set_bits(unsigned int num)
{
	int	count;
	int	bit_pos;
	int	size;

	count = 0;
	bit_pos = 0;
	size = (sizeof(num) * 8);
	while (bit_pos < size)
	{
		if (num & (1 << bit_pos))
			count++;
		bit_pos++;
	}
	return (count);
}

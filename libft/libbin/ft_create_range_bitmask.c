/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_range_bitmask.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:37:39 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/16 22:31:54 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Create a bitmask with bits set to 1 between start_bit and end_bit.
 */
unsigned int	ft_create_range_bitmask(int start_bit, int end_bit)
{
	int					range;
	unsigned int		mask;

	if ((start_bit < 0) || (end_bit < 0)
		|| (unsigned int)start_bit >= (sizeof(unsigned int) * 8)
		|| (unsigned int)end_bit >= (sizeof(unsigned int) * 8))
		return (0);
	if (end_bit > start_bit)
	{
		range = end_bit - start_bit;
		mask = (1u << (range + 1)) - 1;
		mask = mask << start_bit;
	}
	else
	{
		range = start_bit - end_bit;
		mask = (1u << (range + 1)) - 1;
		mask = mask << end_bit;
	}
	return (mask);
}

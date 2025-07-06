/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_bits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:43:01 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/16 23:30:03 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Sets a subset of bits in a number (from start_bit to end_bit) 
 * to a given value.
 */

unsigned int	ft_set_bits(unsigned int n, int st, int en, unsigned int val)
{
	unsigned int	mask;

	if (val > 1)
		return (n);
	mask = ft_create_range_bitmask(st, en);
	if (val == 0)
	{
		n = n & ~(mask);
	}
	else if (val == 1)
	{
		n = n | mask;
	}
	return (n);
}

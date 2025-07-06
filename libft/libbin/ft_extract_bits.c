/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:02:13 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/16 22:56:45 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Extracts a subset of bits from a number (from start_bit to end_bit).
 */
unsigned int	ft_extract_bits(unsigned int n, int st, int e)
{
	unsigned int	mask;
	unsigned int	val;

	mask = ft_create_range_bitmask(st, e);
	val = n & mask;
	return (val >> st);
}

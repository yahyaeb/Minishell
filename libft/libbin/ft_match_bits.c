/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match_bits.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:34:08 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/17 14:51:25 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Checks if a subset of bits matches a specific value.
 */
int	ft_match_bits(unsigned int n, int st, int en, unsigned int val)
{
	unsigned int	subset;
	unsigned int	mask;

	if (val > 1)
		return (-1);
	subset = ft_extract_bits(n, st, en);
	if (val == 0)
	{
		if (subset == 0)
			return (1);
		return (0);
	}
	else if (val == 1)
	{
		mask = ft_create_range_bitmask(st, en);
		if ((subset & mask) == mask)
			return (1);
		return (0);
	}
	return (-1);
}

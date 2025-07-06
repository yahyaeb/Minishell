/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_bits.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:44:16 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/16 10:19:12 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Swaps two bits in a number.
 */
unsigned int	ft_swap_bits(unsigned int n, int b1_pos, int b2_pos)
{
	if ((b1_pos < 0) || (b2_pos < 0)
		|| ((unsigned int)b1_pos >= (sizeof(n) * 8))
		|| ((unsigned int)b2_pos >= (sizeof(n) * 8)))
		return (-1);
	if (((n >> b1_pos) & 1) != ((n >> b2_pos) & 1))
	{
		n = n ^ (1 << b1_pos);
		n = n ^ (1 << b2_pos);
	}
	return (n);
}

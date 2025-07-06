/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_bits.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:43:20 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/20 18:59:59 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Reverse all bits in a number.
 */
unsigned int	ft_reverse_bits(unsigned int num)
{
	unsigned int	rev;

	rev = 0;
	while (num > 0)
	{
		rev <<= 1;
		if ((num & 1) == 1)
			rev |= 1;
		num >>= 1;
	}
	return (rev);
}

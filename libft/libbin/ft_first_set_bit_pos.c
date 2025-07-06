/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_set_bit_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:43:01 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/10 09:06:48 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Gets the position of the first bit set to 1.
 */
int	ft_first_set_bit_pos(unsigned int num)
{
	int	bit_pos;
	int	size;

	bit_pos = 0;
	size = (sizeof(num) * 8);
	while (bit_pos < size)
	{
		if (num & (1 << bit_pos))
			return (bit_pos);
		bit_pos++;
	}
	return (-1);
}

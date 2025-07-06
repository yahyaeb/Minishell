/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_highest_set_bit_pos.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:11:18 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/10 09:45:00 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Gets the position of the most significant bit.
 */

int	highest_set_bit_pos(unsigned int num)
{
	int	bit_pos;

	bit_pos = 0;
	if (num == 0)
		return (-1);
	while (num > 0)
	{
		num >>= 1;
		bit_pos++;
	}
	return (bit_pos - 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toggle_bit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:43:01 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/10 09:07:24 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Toggles the specific bit of num at bit_pos (flips between 1 and 0).
 */
unsigned int	ft_toggle_bit(unsigned int num, int bit_pos)
{
	if (bit_pos < 0 || ((unsigned int)bit_pos >= (sizeof(num) * 8)))
		return (num);
	num = num ^ (1 << bit_pos);
	return (num);
}

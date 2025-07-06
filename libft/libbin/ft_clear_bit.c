/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_bit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:43:01 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/10 09:06:08 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Clears the specific bit of num at bit_pos (sets it to 0).
 */
unsigned int	ft_clear_bit(unsigned int num, int bit_pos)
{
	if (bit_pos < 0 || ((unsigned int)bit_pos >= (sizeof(num) * 8)))
		return (num);
	num = num & ~(1 << bit_pos);
	return (num);
}

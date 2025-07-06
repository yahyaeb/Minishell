/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_bit_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:43:01 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/10 13:59:14 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Checks if the specific bit of num at bit_pos is set (1) or not (0).
 */
int	ft_is_bit_set(unsigned int num, int bit_pos)
{
	int	is_set;

	is_set = 0;
	if (bit_pos < 0 || ((unsigned int)bit_pos >= (sizeof(num) * 8)))
		return (-1);
	if (num & (1 << bit_pos))
		is_set = 1;
	return (is_set);
}

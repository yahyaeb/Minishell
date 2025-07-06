/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arithmetic_shift_right.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:27:48 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/20 16:48:27 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Performs an arithmetic shift right (preserves the sign).
 */
int	ft_arithmetic_shift_right(int num, int shift_amount)
{
	if (shift_amount < 1 || shift_amount > 31 || num == 0)
		return (num);
	return (num >> shift_amount);
}

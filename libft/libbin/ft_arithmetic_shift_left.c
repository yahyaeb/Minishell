/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arithmetic_shift_left.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:03:23 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/20 16:46:13 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Performs an arithmetic shift left (preserves the sign).
 */
int	ft_arithmetic_shift_left(int num, int shift_amount)
{
	if (shift_amount < 1 || shift_amount > 31)
		return (num);
	return (num << shift_amount);
}

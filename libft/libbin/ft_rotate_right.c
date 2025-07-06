/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_right.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:37:30 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/20 16:00:04 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Performs a right circular shift (rotates bits right).
 */
unsigned int	ft_rotate_right(unsigned int n, int shift_amount)
{
	if (shift_amount < 1 || shift_amount > 31)
		return (n);
	return ((n >> shift_amount) | (n << (32 - shift_amount)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_left.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:36:10 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/20 15:53:35 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Performs a left circular shift (rotates bits left).
 */
unsigned int	ft_rotate_left(unsigned int n, int shift_amount)
{
	if (shift_amount < 1 || shift_amount > 31)
		return (n);
	return ((n << shift_amount) | (n >> (32 - shift_amount)));
}

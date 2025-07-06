/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unpack_second_half.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:50:51 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/02 22:20:52 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Unpacks the second 16 bits of a packed 32-bit value.
 */
unsigned int	ft_unpack_second_half(unsigned int packed)
{
	unsigned int	second_half;

	second_half = (packed & 0xFFFF);
	return (second_half);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unpack_first_half.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:49:39 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/02 22:20:43 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Unpacks the first 16 bits of a packed 32-bit value.
 */
unsigned int	ft_unpack_first_half(unsigned int packed)
{
	unsigned int	first_half;

	first_half = packed >> 16;
	return (first_half);
}

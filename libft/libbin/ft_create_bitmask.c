/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_bitmask.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 10:33:47 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/17 14:54:46 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Create a bitmask with n least significant bits set to 1
 */
unsigned int	ft_create_bitmask(int num_bits)
{
	return ((1u << num_bits) - 1);
}

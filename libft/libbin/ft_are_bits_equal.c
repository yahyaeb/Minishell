/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_are_bits_equal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:42:11 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/20 15:25:04 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Tests if two numbers have the same bits set.
 */
int	ft_are_bits_equal(unsigned int n1, unsigned int n2)
{
	if ((n1 ^ n2) == 0)
		return (1);
	else
		return (0);
}

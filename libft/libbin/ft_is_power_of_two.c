/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_power_of_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:40:58 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/20 15:04:04 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Tests if a number is a power of 2.
 */
int	ft_is_power_of_two(unsigned int n)
{
	if (((n & (n - 1)) == 0) && (n != 0))
		return (1);
	else
		return (0);
}

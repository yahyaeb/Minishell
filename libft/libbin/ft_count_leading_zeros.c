/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_leading_zeros.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:45:15 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/20 20:31:10 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Counts the leading zeros in a number.
 */
int	ft_count_leading_zeros(unsigned int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (32);
	while ((n & (1 << 31)) == 0)
	{
		count++;
		n <<= 1;
	}
	return (count);
}

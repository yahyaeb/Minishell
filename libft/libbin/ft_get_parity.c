/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parity.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:47:09 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/20 21:36:16 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Gets the parity of a number (1 if odd number of bits sets, 0 if even).
 */

int	ft_get_parity(unsigned int n)
{
	int	set_count;
	int	bit;

	if (n == 0)
		return (0);
	set_count = 0;
	bit = 32;
	while (bit > 0)
	{
		if ((n & 1) == 1)
			set_count++;
		n >>= 1;
		bit--;
	}
	if (set_count % 2 == 0)
		return (0);
	else
		return (1);
}

/* Brian Kernighan's algorithm. More efficient. Kept here for study purposes.
int	ft_get_parity(unsigned int n)
{
	int	is_odd;

	is_odd = 0;
	while (n)
	{
		is_odd ^= 1;
		n &= n - 1; 
	}
	if (is_odd % 2 == 0)
		return (0);
	else
		return (1);
}
*/

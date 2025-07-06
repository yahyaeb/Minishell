/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:43:01 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/10 14:25:18 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Stores the int num in binary notation in the array binary.
 */
void	ft_get_bin(int num, char binary[33])
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if (num & (1 << i))
			binary[31 - i] = '1';
		else
			binary[31 - i] = '0';
		i--;
	}
	binary[32] = '\0';
}

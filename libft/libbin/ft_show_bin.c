/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 08:43:01 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/10 09:07:14 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Displays the int num in binary notation.
 */
void	ft_show_bin(int num, unsigned int nb_of_bytes)
{
	unsigned int	size;
	int				i;

	size = sizeof(num) * 8;
	if (nb_of_bytes > size)
		nb_of_bytes = size ;
	i = size - 1;
	while (i >= (int)(size - nb_of_bytes))
	{
		ft_printf("%d", (num >> i) & 1);
		i--;
	}
}

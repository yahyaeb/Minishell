/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pack_two_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 20:48:21 by mmalie            #+#    #+#             */
/*   Updated: 2025/01/02 22:20:29 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Packs two integers into a single 32-bit value.
 */
unsigned int	ft_pack_two_int(unsigned int n1, unsigned int n2)
{
	unsigned int	package;

	package = (n1 & 0xFFFF);
	package <<= 16;
	package = package | (n2 & 0xFFFF);
	return (package);
}

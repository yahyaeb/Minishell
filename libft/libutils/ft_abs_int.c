/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:20:48 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/05 11:29:24 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Get the absolute value (without the sign) of an int.
 * Only if the number is negative ("+" will not be removed.)
 */
int	ft_abs_int(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

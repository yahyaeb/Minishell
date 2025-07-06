/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:34:01 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:28:22 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Implementation of isascii() from <ctype.h>: Checks if the given character 
 * is a valid ASCII character (0-127).
 */
int	ft_isascii(int c)
{
	return ((c >= 0) && (c <= 127));
}

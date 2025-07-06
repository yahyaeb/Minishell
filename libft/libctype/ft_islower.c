/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:34:01 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:28:14 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Implementation of islower() from <ctype.h>: Checks if the given character 
 * is lowercase.
 */
int	ft_islower(int c)
{
	return ((c >= 'a') && (c <= 'z'));
}

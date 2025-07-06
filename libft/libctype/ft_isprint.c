/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:43:37 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:28:44 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Implementation of isprint() from <ctype.h>: Checks if the given character 
 * is printable (includes space and visible characters).
*/
int	ft_isprint(int c)
{
	return ((c >= 32) && (c <= 126));
}

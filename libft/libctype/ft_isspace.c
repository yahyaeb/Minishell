/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:33:29 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:27:24 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Implementation of isspace() from <libctype.h>:
 * Checks for white-space characters.
 */

int	ft_isspace(int c)
{
	return (c == 32 || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v');
}

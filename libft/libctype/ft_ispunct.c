/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:34:01 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:28:14 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Implementation of ispunct() from <ctype.h>: Checks if the given character 
 * is a punctuation ASCII character.
 */
int	ft_ispunct(int c)
{
	return (((c >= 33) && (c <= 47))
		|| ((c >= 58) && (c <= 64))
		|| ((c >= 91) && (c <= 96))
		|| ((c >= 123) && (c <= 126)));
}

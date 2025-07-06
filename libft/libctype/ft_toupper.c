/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:43:58 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:34:10 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Implementation of toupper() from <ctype.h>: Converts a lowercase character 
 * to uppercase.
*/
int	ft_toupper(int c)
{
	if ((c >= 'a') && (c <= 'z'))
	{
		return (c - ('a' - 'A'));
	}
	else
	{
		return (c);
	}
}

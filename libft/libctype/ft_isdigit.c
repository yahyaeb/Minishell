/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:34:13 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:28:36 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * Implementation of isdigit() from <ctype.h>: Checks if the given character 
 * is a numeric digit (0-9).
*/
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

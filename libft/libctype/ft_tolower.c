/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:44:11 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:33:54 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Implementation of tolower() from <ctype.h>: Converts an uppercase character 
 * to lowercase.
*/
int	ft_tolower(int c)
{
	if ((c >= 'A') && (c <= 'Z'))
	{
		return (c + ('a' - 'A'));
	}
	else
	{
		return (c);
	}
}

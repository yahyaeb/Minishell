/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:34:01 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:28:14 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Implementation of strrev() from <string.h>: Reverses the given string.
 */
char	*ft_strrev(char *str)
{
	char	*first;
	char	*last;
	char	temp;

	if (str == NULL || *str == '\0')
		return (str);
	first = str;
	last = str;
	while (*last != '\0')
		last++;
	last--;
	while (first < last)
	{
		temp = *first;
		*first = *last;
		*last = temp;
		first++;
		last--;
	}
	return (str);
}

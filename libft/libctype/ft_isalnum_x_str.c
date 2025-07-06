/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_x_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:04:00 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/05 19:16:52 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* Return 0 if str contains only alphanumerical characters and chars in set.
 */
int	ft_isalnum_x_str(char *str, char *set)
{
	int	i;

	i = 0;
	if (!str[0])
		return (0);
	while (str[i] != '\0')
	{
		if (!ft_isalnum(str[i]) && !ft_is_in_set(str[i], set))
			return (1);
		i++;
	}
	return (0);
}

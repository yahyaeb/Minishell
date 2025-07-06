/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/27 13:22:38 by mmalie            #+#    #+#             */
/*   Updated: 2025/04/27 13:25:07 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_count_char(char *str, char c)
{
	size_t	str_len;
	size_t	i;
	int		count;

	str_len = ft_strlen(str);
	i = 0;
	count = 0;
	while (i < str_len)
	{
		if (str[i] == c)
			count++;
		i++;
	}
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_ints.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:25:38 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/05 11:45:32 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * This variadic function initializes several int variables to the same value
 * (probably 0) in order to save some lines.
 */
void	ft_init_ints(int init_value, int count, ...)
{
	va_list	args;
	int		*cur_int_arg;
	int		i;

	va_start(args, count);
	i = 0;
	while (i < count)
	{
		cur_int_arg = va_arg(args, int *);
		*cur_int_arg = init_value;
		i++;
	}
	va_end(args);
	return ;
}

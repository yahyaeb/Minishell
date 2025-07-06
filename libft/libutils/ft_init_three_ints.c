/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_three_ints.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:25:38 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/12 10:25:00 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * As ft_init_ints might not pass the 42 Norm because of the use of variadic
 * functions, this version does the same for three ints.
 */
void	ft_init_three_ints(int init_value, int *int_1, int *int_2, int *int_3)
{
	*int_1 = init_value;
	*int_2 = init_value;
	*int_3 = init_value;
	return ;
}

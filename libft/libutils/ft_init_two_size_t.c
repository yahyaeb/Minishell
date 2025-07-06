/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_two_size_t.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:25:38 by mmalie            #+#    #+#             */
/*   Updated: 2025/04/14 20:28:58 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/*
 * As ft_init_size_t would not pass the 42 Norm because of the use of variadic
 * functions, this version does the same for two size_t.
 */
void	ft_init_two_size_t(size_t init_value, size_t *nb_1, size_t *nb_2)
{
	*nb_1 = init_value;
	*nb_2 = init_value;
	return ;
}

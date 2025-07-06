/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_x_chr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:04:00 by mmalie            #+#    #+#             */
/*   Updated: 2025/05/19 22:35:22 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/* Return 1 if the char is alphanumerical or one of the chars in set.
 */
int	ft_isalnum_x_chr(char *chr, char *set)
{
	if (!chr)
		return (0);
	return (ft_isalnum(*chr) || ft_is_in_set(*chr, set));
}

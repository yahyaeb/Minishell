/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:01:01 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:30:34 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Returns the number of nodes in a linked list.
 */
int	ft_lstsize(t_list *lst)
{
	int	lst_size;

	lst_size = 0;
	while (lst != NULL)
	{
		lst_size++;
		lst = lst->next;
	}
	return (lst_size);
}

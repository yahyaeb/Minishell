/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:01:10 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:30:10 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Returns the last node in a linked list.
 */
t_list	*ft_lstlast(t_list *lst)
{
	t_list	*last_node;

	if (lst == NULL)
	{
		return (NULL);
	}
	last_node = lst;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	return (last_node);
}

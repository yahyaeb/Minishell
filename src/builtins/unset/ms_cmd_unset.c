/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_unset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:04:03 by mmalie            #+#    #+#             */
/*   Updated: 2025/05/12 23:46:19 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

// Remove requested vars from this_env.
int	cmd_unset(t_shell *sh) // NEED TO ADD ERRORS ON WRONG INPUT!!!
{
	t_list	*tgt_node;
	t_list	*prev_node;
	int		i;

	if (!sh->input_args[1])
		return (0);
	i = 1;
	while (sh->input_args[i])
	{
		tgt_node = ft_getenv(sh->input_args[i], &sh->this_env);
		if (tgt_node != NULL)
		{
			if (tgt_node == sh->this_env)
				sh->this_env = tgt_node->next;
			else
			{
				prev_node = get_prev_node(tgt_node, sh->this_env);
				prev_node->next = tgt_node->next;
			}
			free_args(tgt_node->content);
			free(tgt_node);
		}
		i++;
	}
	return (0);
}

t_list	*get_prev_node(t_list *cur_node, t_list *this_env)
{
	t_list	*prev_node;

	prev_node = this_env;
	while (prev_node->next != cur_node)
		prev_node = prev_node->next;
	return (prev_node);
}

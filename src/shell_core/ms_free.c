/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:23:34 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/17 19:07:31 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	free_memory(t_shell *sh)
{
	if (sh->normalized_line != NULL)
		free(sh->normalized_line);
	if (sh->this_env != NULL)
		free_list(&sh->this_env);
	if (sh->env_stash != NULL)
		free_list(&sh->env_stash);
	if (sh->cmds != NULL)
		free_commands(sh->cmds);
	rl_clear_history();
}

void	free_args(char **input_args)
{
	int	i;

	i = 0;
	while (input_args[i])
	{
		free(input_args[i]);
		i++;
	}
	free(input_args);
}

void	free_list(t_list **list)
{
	t_list	*cur_node;
	t_list	*prev_node;
	int		i;

	if (list != NULL && *list != NULL)
	{
		cur_node = *list;
		while (cur_node != NULL)
		{
			if (cur_node->content != NULL)
			{
				i = 0;
				while (((char **)cur_node->content)[i])
					free(((char **)cur_node->content)[i++]);
				free(((char **)cur_node->content));
				cur_node->content = NULL;
			}
			prev_node = cur_node;
			cur_node = cur_node->next;
			free(prev_node);
		}
		*list = NULL;
	}
}

void	free_commands(t_command **cmds)
{
	int		i;

	i = 0;
	if (cmds != NULL)
	{
		while (i < NB_CMDS)
		{
			if (cmds[i]->name != NULL)
				free(cmds[i]->name);
			if (cmds[i]->doc != NULL)
				free(cmds[i]->doc);
			free(cmds[i]);
			i++;
		}
		free(cmds);
	}
}

char	*free_incomplete_strs(char **arr, int up_to)
{
	int	i;

	i = 0;
	while (i < up_to)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

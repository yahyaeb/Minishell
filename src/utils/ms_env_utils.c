/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_env_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 11:12:12 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/15 14:15:44 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_list	*ft_getenv(char *var_name, t_list **this_env)
{
	t_list	*cur_node;
	int		res;

	cur_node = *this_env;
	while (cur_node != NULL)
	{
		res = ft_strcmp(var_name, (((char **)cur_node->content)[0]));
		if (res == 0)
			return (cur_node);
		cur_node = cur_node->next;
	}
	return (NULL);
}

char	*ft_setenv(t_list *set_var, char *arg)
{
	if (arg != NULL)
	{
		free(arg);
		if (set_var != NULL && ((char **)set_var->content)[1] != NULL)
			arg = ft_strdup(((char **)set_var->content)[1]);
		else
			arg = ft_strdup("");
		return (arg);
	}
	else
		arg = ft_strdup("");
	return (arg);
}

int	is_valid_env_name(char *var_name)
{
	size_t	i;

	i = 0;
	if (!var_name || var_name[0] == '\0'
		|| var_name[0] == '='
		|| ft_isdigit(var_name[0]))
		return (0);
	while (var_name[i])
	{
		if (!ft_isalnum(var_name[i])
			&& var_name[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

// add a new node with split_str content to the end of the list
int	add_new_env_var(t_shell *sh, char **split_str)
{
	t_list	*new_node;

	new_node = ft_lstnew((char **)split_str);
	if (!new_node)
	{
		free_args(split_str);
		return (-1);
	}
	ft_lstadd_back(&sh->this_env, new_node);
	return (0);
}

// free previous content, malloc for new content and copy it from split_str
int	ft_update_env_value(t_list *set_var, char **split_str)
{
	if (set_var->content)
		free_args(set_var->content);
	set_var->content = split_str;
	return (0);
}

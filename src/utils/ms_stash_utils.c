/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_stash_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 17:42:15 by mmalie            #+#    #+#             */
/*   Updated: 2025/05/21 23:48:00 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	stash_var(t_shell *sh)
{
	char	**split_str;
	size_t	i;
	size_t	nb_args;

	i = 0;
	split_str = NULL;
	nb_args = ft_strslen(sh->input_args);
	while (i < nb_args)
	{
		split_str = split_input_arg(sh, &i);
		if (!split_str)
			return (1);
		if (!is_valid_env_name(split_str[0]))
		{
			free_args(split_str);
			return (2);
		}
		if (handle_stashing(sh, split_str) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	handle_stashing(t_shell *sh, char **split_str)
{
	t_list	*stashed_var;

	stashed_var = ft_getenv(split_str[0], &sh->env_stash);
	if (stashed_var != NULL)
	{
		if (ft_update_env_value(stashed_var, split_str) != 0)
		{
			free_args(split_str);
			return (-1);
		}
	}
	else
	{
		if (add_new_stash_var(sh, split_str) != 0)
			return (-1);
	}
	return (0);
}

int	is_valid_env_name_sub(char *arg)
{
	char	*equal_char;
	char	*var_name;
	size_t	len;

	equal_char = ft_strchr(arg, '=');
	if (equal_char == NULL)
		return (1);
	len = (size_t)(equal_char - arg);
	var_name = ft_substr(arg, 0, len);
	if (!is_valid_env_name(var_name))
	{
		free(var_name);
		return (1);
	}
	free(var_name);
	return (0);
}

int	are_args_stashable(char **args)
{
	char	*invalid_cmd;
	int		i;

	i = 0;
	while (args[i] != NULL)
	{
		if (ft_strchr(args[i], '/') != NULL)
			return (1);
		invalid_cmd = ft_strchr(args[i], '=');
		if ((invalid_cmd == NULL)
			|| (is_valid_env_name_sub(args[i]) != 0))
			return (1);
		i++;
	}
	return (0);
}

// add a new node with split_str content to the end of the list
int	add_new_stash_var(t_shell *sh, char **split_str)
{
	t_list	*new_node;

	new_node = ft_lstnew((char **)split_str);
	if (!new_node)
	{
		free_args(split_str);
		return (-1);
	}
	ft_lstadd_back(&sh->env_stash, new_node);
	return (0);
}

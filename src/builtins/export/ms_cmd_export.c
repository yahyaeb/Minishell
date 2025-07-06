/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_export.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:03:40 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/17 16:51:27 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

void	exec_export_no_arg(t_shell *sh)
{
	char	**env_array;
	int		count;

	env_array = env_list_to_array(sh->this_env);
	count = count_args(env_array);
	sort_env_array(env_array, count);
	print_sorted_export(env_array);
	free_args(env_array);
}

// Handle "export var_name" (from stash) & "export var_name=[value]"
int	cmd_export(t_shell *sh)
{
	size_t	i;
	int		res;

	if (sh->input_args[1] == NULL)
	{
		exec_export_no_arg(sh);
		return (0);
	}
	else
	{
		i = 1;
		while (sh->input_args[i] != NULL)
		{
			if (sh->input_args[i][0] == '='
				|| ft_isdigit(sh->input_args[i][0]))
				return (ms_err("export: `", sh->input_args[i], INVALID_ID, 1));
			res = try_export(sh, &i);
			if (res != 0)
				return (res);
			i++;
		}
	}
	return (0);
}

int	try_export(t_shell *sh, size_t *i)
{
	t_list	*stashed_var;
	int		res;

	if (ft_strchr(sh->input_args[(*i)], '=') == NULL)
	{
		if (ft_isalnum_x_str(sh->input_args[(*i)], "_") != 0)
			return (ms_err("export: `", sh->input_args[(*i)], INVALID_ID, 1));
		stashed_var = ft_getenv(sh->input_args[(*i)], &sh->env_stash);
		if (stashed_var != NULL)
			export_from_stash(sh, stashed_var);
	}
	else
	{
		res = 0;
		res = export_from_term(sh, i);
		if (res != 0)
			return (res);
	}
	return (0);
}

int	export_from_term(t_shell *sh, size_t *i)
{
	t_list	*set_var;
	char	**split_str;

	split_str = split_input_arg(sh, i);
	if (!split_str)
		return (1);
	if (!is_valid_env_name(split_str[0]))
	{
		free_args(split_str);
		return (ms_err("export: `", sh->input_args[(*i)], INVALID_ID, 1));
	}
	set_var = ft_getenv(split_str[0], &sh->this_env);
	if (set_var != NULL)
	{
		if (ft_update_env_value(set_var, split_str) != 0)
		{
			free_args(split_str);
			return (1);
		}
	}
	else
		add_new_env_var(sh, split_str);
	return (0);
}

void	export_from_stash(t_shell *sh, t_list *stashed_var)
{
	t_list	*set_var;
	t_list	*prev_node;
	char	**new_content;

	set_var = ft_getenv(((char **)stashed_var->content)[0], &sh->this_env);
	new_content = ft_strsdup((char **)stashed_var->content);
	if (!new_content)
		return ;
	if (set_var != NULL)
		ft_update_env_value(set_var, new_content);
	else
		add_new_env_var(sh, new_content);
	prev_node = sh->env_stash;
	if (stashed_var == sh->env_stash)
		sh->env_stash = stashed_var->next;
	else
	{
		while (prev_node && prev_node->next != stashed_var)
			prev_node = prev_node->next;
		if (prev_node)
			prev_node->next = stashed_var->next;
	}
	if (stashed_var->content)
		free_args((char **)stashed_var->content);
	free(stashed_var);
}

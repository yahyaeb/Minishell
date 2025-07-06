/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_nametoval.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 21:03:21 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/14 20:13:16 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	*ft_nametoval(t_shell *sh, char *rejoined, char **split_args)
{
	int		i;
	int		j;
	char	*end_name;

	i = 0;
	while (split_args[i])
	{
		if (split_args[i][0] == '?')
			rejoined = handle_exit_status_case(
					sh, rejoined, split_args[i]);
		else
		{
			j = 0;
			while (split_args[i][j] && ft_isalnum_x_chr(&split_args[i][j], "_"))
				j++;
			end_name = &(split_args[i][j]);
			if (*end_name != '\0')
				rejoined = handle_special_cases(sh, rejoined,
						split_args[i], end_name);
			else
				rejoined = split_rejoin(sh, rejoined, split_args[i], '\0');
		}
		i++;
	}
	return (rejoined);
}

char	*rejoin_subarg(char **subargs, char *delim)
{
	char	*arg;
	char	*temp;

	if (delim[0] == '\0')
		arg = join_all_subargs(subargs, 'n');
	else
	{
		temp = ft_strdup(subargs[0]);
		free(subargs[0]);
		subargs[0] = ft_strjoin(temp, delim);
		arg = join_all_subargs(subargs, 'n');
		free(temp);
	}
	return (arg);
}

char	*split_rejoin(t_shell *sh, char *rejoined_arg, char *arg, char symbol)
{
	char	**subargs;
	t_list	*set_var;
	char	*delim;

	subargs = ft_split(arg, CC_SUBARG_DELIM);
	set_var = ft_getenv(subargs[0], &sh->this_env);
	subargs[0] = ft_setenv(set_var, subargs[0]);
	delim = to_delim(sh, subargs, symbol);
	if (!delim)
		return (NULL);
	arg = rejoin_subarg(subargs, delim);
	if (DEBUG == 1)
		printf("arg: %s\n", arg);
	free(delim);
	free_args(subargs);
	if (!arg)
		return (NULL);
	rejoined_arg = ft_rejoin_subarg(arg, rejoined_arg);
	free(arg);
	return (rejoined_arg);
}

// Set the delim str used to replace the splitter char (restore punct if apply)
char	*to_delim(t_shell *sh, char **subargs, char symbol)
{
	char	*delim;

	delim = malloc(2);
	if (!delim)
		return (NULL);
	delim[0] = '\0';
	if (symbol == CC_SPACE_IN_QUOTE)
		delim[0] = ' ';
	else if (symbol == CC_VAR_BOUND)
	{
		if (ft_getenv(subargs[0], &sh->this_env) == NULL)
			delim[0] = CC_EMPTY_STR;
		else
			delim[0] = '\0';
	}
	else if (symbol == CC_VAR_BOUND_SQUOTE)
		delim[0] = '\'';
	else
		delim[0] = symbol;
	delim[1] = '\0';
	return (delim);
}

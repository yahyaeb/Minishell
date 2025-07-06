/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_echo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:17:12 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/14 15:40:02 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	cmd_echo(t_shell *sh)
{
	char	*joined_input;
	bool	opt_n;
	int		i;

	if (!sh->input_args || !(sh->input_args[1]))
		return (ft_ret(0, "\n", STDOUT));
	i = 0;
	while (ft_strcmp(sh->input_args[i], "echo") != 0)
		i++;
	if (!sh->input_args[i + 1])
		return (ft_ret(0, "\n", STDOUT));
	i++;
	echo_set_n(sh->input_args, &opt_n, &i);
	if (!sh->input_args[i])
		return (ft_ret(0, "", STDOUT));
	joined_input = ft_strdup("");
	joined_input = echo_process_all_args(sh, joined_input, &i);
	if (joined_input == NULL)
		return (-1);
	echo_display(joined_input, opt_n);
	free(joined_input);
	return (0);
}

void	echo_set_n(char **input_args, bool *opt_n, int *i)
{
	if (input_args[(*i)] && input_args[(*i)][0] == '-'
		&& !ft_strnopbrk(&input_args[(*i)][1], "n"))
	{
		*opt_n = true;
		while (input_args[(*i)])
		{
			if (input_args[(*i)][0] == '-'
				&& !ft_strnopbrk(&input_args[(*i)][1], "n"))
				(*i)++;
			else
				break ;
		}
	}
	else
		*opt_n = false;
}

char	*echo_process_all_args(t_shell *sh, char *joined_input, int *i)
{
	ft_replace_all_chars(sh->input_args, CC_PIPE, '|');
	ft_replace_all_chars(sh->input_args, CC_SPACE_IN_QUOTE, ' ');
	replace_cc_empty_str(sh);
	while (sh->input_args[(*i)])
	{
		if (sh->input_args[(*i)])
		{
			joined_input = echo_join_input(joined_input, sh->input_args, i);
			if (!joined_input)
				return (NULL);
		}
		else
			(*i)++;
	}
	return (joined_input);
}

char	*echo_join_input(char *joined_input, char **input_args, int *i)
{
	char	*temp_1;
	char	*temp_2;

	temp_1 = ft_strjoin(joined_input, input_args[(*i)]);
	if (!temp_1)
		return (NULL);
	if (joined_input)
		free(joined_input);
	joined_input = ft_strdup(temp_1);
	free(temp_1);
	if (!joined_input)
		return (NULL);
	(*i)++;
	if (input_args[(*i)] != NULL)
	{
		temp_2 = ft_strjoin(joined_input, " ");
		if (!temp_2)
			return (NULL);
		free(joined_input);
		joined_input = ft_strdup(temp_2);
		free(temp_2);
		if (!joined_input)
			return (NULL);
	}
	return (joined_input);
}

void	echo_display(char *joined_output, bool opt_n)
{
	if (joined_output != NULL)
		printf("%s", joined_output);
	if (opt_n == false)
		printf("\n");
	return ;
}

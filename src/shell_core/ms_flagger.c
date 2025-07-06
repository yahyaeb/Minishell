/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_flagger.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:03:35 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/13 07:14:39 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	flag_dollar(char *line, int *i)
{
	if (line[(*i) + 1])
	{
		if (ft_is_in_set(line[(*i) + 1], "\"\'")
			&& ft_count_char(&line[(*i) + 1], line[(*i) + 1]) > 1)
			ft_replace_char(&line[(*i)], CC_LONE_DOLLAR);
		else if (ft_isalnum_x_chr(&line[(*i) + 1], "_?"))
			ft_replace_char(&line[(*i)], CC_VAR_TO_INTERPRET);
	}
	return ;
}

void	flag_pipe_and_redir(char *line, int *i)
{
	if (line[(*i)] == '|')
		ft_replace_char(&line[(*i)], CC_PIPE);
	else if (line[(*i)] == '<' && line[(*i) + 1] == '<')
	{
		ft_replace_char(&line[(*i)], CC_HEREDOC);
		ft_replace_char(&line[(*i) + 1], ' ');
		(*i)++;
	}
	else if (line[(*i)] == '>' && line[(*i) + 1] == '>')
	{
		ft_replace_char(&line[(*i)], CC_APPEND);
		ft_replace_char(&line[(*i) + 1], ' ');
		(*i)++;
	}
	else if (line[(*i)] == '<')
		ft_replace_char(&line[(*i)], CC_REDIR_IN);
	else if (line[(*i)] == '>')
		ft_replace_char(&line[(*i)], CC_REDIR_OUT);
}

void	flag_quote(char *line, int *i)
{
	if (line[(*i)] == '\'' && ft_count_char(&line[(*i)], '\'') > 1)
		handle_quote(line, '\'', i);
	else if (line[(*i)] == '\"' && ft_count_char(&line[(*i)], '\"') > 1)
	{
		if ((*i) > 0 && !ft_is_in_set(line[(*i) - 1], " \"\'"))
			ante_merge_quote(line, i);
		handle_quote(line, '\"', i);
		if (!line[(*i) + 1] || ft_is_in_set(line[(*i + 1)], " \"\'"))
			return ;
	}
	else if ((ft_is_in_set(line[(*i)], "\"\'"))
		&& (ft_count_char(&line[(*i)], '\"') == 1
			|| ft_count_char(&line[(*i)], '\'') == 1))
	{
		ft_replace_chars_in_str(&line[(*i)], '$', CC_DOLLAR_UNCLOSED);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_quotes_handler.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                               +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 12:57:41 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/14 19:55:27 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	flag_var_bounds(char *line, int *i)
{
	ft_replace_char(&line[(*i)++], CC_VAR_TO_INTERPRET);
	while (ft_isalnum_x_chr(&line[(*i)], "_?"))
		(*i)++;
	if (line[(*i)] == '\'')
		line[(*i)] = CC_VAR_BOUND_SQUOTE;
	else if (line[(*i)] == '\"')
		line[(*i)] = CC_VAR_BOUND;
	(*i)--;
}

void	handle_quote(char *line, char quote_type, int *i)
{
	(*i)++;
	if (quote_type == '\'' && ft_count_char(&line[(*i - 1)], '\'') > 1)
	{
		while (line[(*i)] != '\'')
			ft_replace_if_space(&line[(*i)++], CC_SPACE_IN_QUOTE);
	}
	else if (quote_type == '\"' && ft_count_char(&line[(*i - 1)], '\"') > 0)
	{
		while (line[(*i)] != '\"' && line[(*i)] != CC_VAR_BOUND)
		{
			if (line[(*i)] == '$' && ft_isalnum_x_chr(&line[(*i) + 1], "_?"))
				flag_var_bounds(line, i);
			else if (line[(*i)] != '\"' && line[(*i)] != CC_VAR_BOUND
				&& line[(*i)] != CC_VAR_BOUND_SQUOTE)
				ft_replace_if_space(&line[(*i)], CC_SPACE_IN_QUOTE);
			(*i)++;
		}
	}
}

void	ante_merge_quote(char *line, int *i)
{
	int	temp_i;

	if ((*i) > 0 && !ft_is_in_set(line[(*i) - 1], " \"\'")
		&& line[(*i) - 1] != CC_VAR_BOUND
		&& ft_strchr(line, CC_VAR_TO_INTERPRET) != NULL)
	{
		temp_i = (*i);
		while (temp_i > 0 && line[temp_i] != ' ')
		{
			temp_i--;
			if (line[temp_i] == CC_VAR_TO_INTERPRET)
			{
				ft_replace_char(&line[(*i)], CC_VAR_BOUND);
				break ;
			}
		}
	}
}

void	pass_quotes(char *dst, char *src, size_t *i, size_t *j)
{
	if (two_quotes_case(dst, src, i, j) != 0)
		return ;
	else if (src[(*i)] == '\'' || src[(*i)] == CC_VAR_BOUND_SQUOTE)
	{
		if (src[(*i)] == CC_VAR_BOUND_SQUOTE)
			dst[(*j)++] = src[(*i)];
		(*i)++;
		while (src[(*i)] && src[(*i)] != '\''
			&& src[(*i)] != CC_VAR_BOUND_SQUOTE)
			dst[(*j)++] = src[(*i)++];
		if (src[(*i)] == CC_VAR_BOUND_SQUOTE)
			dst[(*j)++] = src[(*i)];
		(*i)++;
	}
	else if (src[(*i)] == '\"' || src[(*i)] == CC_VAR_BOUND)
	{
		if (src[(*i)] == CC_VAR_BOUND)
			dst[(*j)++] = src[(*i)];
		(*i)++;
		while (src[(*i)] && src[(*i)] != '\"' && src[(*i)] != CC_VAR_BOUND)
			dst[(*j)++] = src[(*i)++];
		if (src[(*i)] == CC_VAR_BOUND)
			dst[(*j)++] = src[(*i)];
		(*i)++;
	}
}

int	two_quotes_case(char *dst, char *src, size_t *i, size_t *j)
{
	if (!src[2] && ft_is_in_set(src[0], "\"\'")
		&& ft_is_in_set(src[1], "\"\'"))
	{
		while (src[(*i)])
		{
			dst[(*j)] = src[(*i)];
			(*j)++;
			(*i)++;
		}
		return (1);
	}
	return (0);
}

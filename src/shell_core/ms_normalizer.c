/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_normalizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 23:57:21 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/16 08:58:34 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// Returns a normalized (trimmed, flagged and spaced) line
char	*ft_normalize(char *line)
{
	char	*trimmed;
	char	*flagged;
	char	*spaced;

	trimmed = ft_strtrim(line, " \f\n\r\t\v");
	if (trimmed == NULL)
		return (NULL);
	flagged = ft_strflag(trimmed);
	free(trimmed);
	if (flagged == NULL)
		return (NULL);
	spaced = ft_add_spaces_around(flagged, CC_PIPE);
	free(flagged);
	if (!spaced)
		return (NULL);
	spaced = ft_add_spaces_around_redir(spaced);
	return (spaced);
}

// If there is more than one consecutive space, they are suppressed.
char	*ft_strflag(char *line)
{
	char	*flagged_line;
	size_t	line_len;
	int		i;

	flagged_line = NULL;
	i = 0;
	while (line[i])
	{
		if (line[i] == '\0')
			break ;
		if (line[i] == '$')
			flag_dollar(line, &i);
		else if (ft_is_in_set(line[i], "|<>"))
			flag_pipe_and_redir(line, &i);
		else if (ft_is_in_set(line[i], "\"\'"))
			flag_quote(line, &i);
		i++;
	}
	ft_replace_chars_in_str(line, CC_DOLLAR_UNCLOSED, '$');
	line_len = ft_strlen(line);
	flagged_line = malloc(sizeof(char) * ((line_len + 1)));
	if (!flagged_line)
		return (NULL);
	flagged_line = copy_collapse(flagged_line, line, line_len);
	return (flagged_line);
}

void	flag_double_quotes(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		if ((src[i] == '\"')
			&& (i == 0 || (src[i - 1] && src[i - 1] == ' '))
			&& (src[i + 1] && src[i + 1] == '\"')
			&& ((src[i + 2] && (src[i + 2] == ' ' || src[i + 2] == '\0'))))
		{
			ft_replace_char(&src[i], CC_EMPTY_STR);
			ft_replace_char(&src[i + 1], CC_EMPTY_STR);
		}
		else if ((src[i] == '\'')
			&& (i == 0 || (src[i - 1] && src[i - 1] == ' '))
			&& (src[i + 1] && src[i + 1] == '\'')
			&& ((src[i + 2] && (src[i + 2] == ' ' || src[i + 2] == '\0'))))
		{
			ft_replace_char(&src[i], CC_EMPTY_STR);
			ft_replace_char(&src[i + 1], CC_EMPTY_STR);
		}
		i++;
	}
	return ;
}

char	*replace_cc_empty_str(t_shell *sh)
{
	int		i;
	char	**split_arg;

	i = 0;
	while (sh->input_args[i])
	{
		ft_replace_chars_in_str(sh->input_args[i], CC_VAR_BOUND, CC_EMPTY_STR);
		if (sh->input_args[i][0] == CC_EMPTY_STR && sh->input_args[i][1]
			&& sh->input_args[i][1] == CC_EMPTY_STR)
		{
			free(sh->input_args[i]);
			sh->input_args[i] = ft_strdup("");
			if (sh->input_args[i] == NULL)
				return (NULL);
		}
		else if (ft_strchr(sh->input_args[i], CC_EMPTY_STR) != NULL)
		{
			split_arg = ft_split(sh->input_args[i], CC_EMPTY_STR);
			free(sh->input_args[i]);
			sh->input_args[i] = join_all_subargs(split_arg, 'n');
			free_args(split_arg);
		}
		i++;
	}
	return (NULL);
}

// Both the src and dst are expected to be non-NULL and their size is correct
char	*copy_collapse(char *dst, char *src, size_t src_len)
{
	size_t	i;
	size_t	j;

	if (!src)
		return (NULL);
	ft_init_two_size_t(0, &i, &j);
	flag_double_quotes(src);
	while (i < src_len)
	{
		if ((src[i + 1])
			&& ((src[i] == '\'' && ft_count_char(&src[i], '\'') > 1)
				|| (src[i] == '\"' && ((ft_count_char(&src[i], '\"') > 1)
						|| (ft_count_char(&src[i], CC_VAR_BOUND) > 0)))
				|| src[i] == CC_VAR_BOUND
				|| src[i] == CC_VAR_BOUND_SQUOTE))
			pass_quotes(dst, src, &i, &j);
		else if ((ft_isspace(src[i]) && ft_isspace(src[i + 1]))
			|| (src[i] == CC_LONE_DOLLAR))
			i++;
		else
			dst[j++] = src[i++];
	}
	dst[j] = '\0';
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_classifier_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 11:23:56 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/04 10:14:39 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

t_cmd_type	check_cmd_class(t_cmd_flags flags)
{
	if (flags.consecutive_redirs)
		return (MIXED_INVALID);
	if (flags.here_doc)
		return (HERE_DOC);
	if (flags.has_pipe && flags.has_redir)
		return (PIPELINE_WITH_RED);
	if (flags.has_pipe)
		return (PIPELINE);
	if (flags.has_redir)
	{
		if (flags.first_is_redir)
			return (BASIC);
		return (REDIR_ONLY);
	}
	if (flags.has_cmd)
		return (BASIC);
	return (BASIC);
}

int	check_pipe(char **tokens, int i, t_cmd_flags *flags)
{
	if (is_token_control_char(tokens[i], CC_PIPE))
	{
		flags->has_pipe = 1;
		if (!tokens[i + 1])
			return (1);
	}
	return (0);
}

int	check_heredoc(char **tokens, int *i, t_cmd_flags *flags)
{
	if (is_token_control_char(tokens[*i], CC_HEREDOC))
	{
		flags->here_doc = 1;
		if (!tokens[*i + 1])
			return (1);
		(*i)++;
	}
	return (0);
}

void	check_normal_cmd(char **tokens, int i, t_cmd_flags *flags)
{
	if ((unsigned char)tokens[i][0] >= 32)
	{
		flags->has_cmd = 1;
		flags->consecutive_redirs = 0;
	}
}

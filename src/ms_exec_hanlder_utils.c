/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_hanlder_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:21:24 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/17 04:56:39 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	handle_pipeline_with_red(t_shell *sh, char **env)
{
	t_pipeline	*pipeline;

	pipeline = build_pipeline_from_tokens(sh->input_args);
	if (!pipeline)
	{
		sh->last_exit_status = 1;
		return ;
	}
	if (has_heredoc(pipeline))
		run_pipex_from_minshell(pipeline, env, sh->last_exit_status);
	else
		run_pipeline_basic_pipeline(pipeline, env, sh);
	free_pipeline(pipeline);
}

bool	handle_input_redirection(char **tokens, int *i, t_shell *sh)
{
	if (!tokens[*i + 1])
	{
		ft_putstr_fd(" Error: missing input file\n", 2);
		sh->last_exit_status = 1;
		return (false);
	}
	restore_quoted_spaces(tokens[*i + 1]);
	if (access(tokens[*i + 1], R_OK) != 0)
	{
		perror(tokens[*i + 1]);
		sh->last_exit_status = 1;
		return (false);
	}
	(*i)++;
	return (true);
}

bool	handle_output_redirection(char **tokens, int *i, t_shell *sh)
{
	int	fd;
	int	flags;

	flags = O_WRONLY | O_CREAT | O_APPEND;
	if (!tokens[*i + 1])
	{
		ft_putstr_fd(" Error: missing output file\n", 2);
		sh->last_exit_status = 1;
		return (false);
	}
	restore_quoted_spaces(tokens[*i + 1]);
	fd = open(tokens[*i + 1], flags, 0644);
	if (fd < 0)
	{
		perror(tokens[*i + 1]);
		sh->last_exit_status = 1;
		return (false);
	}
	close(fd);
	(*i)++;
	return (true);
}

bool	handle_pipe(char **tokens, int i, t_shell *sh)
{
	if (!tokens[i + 1])
	{
		ft_putstr_fd(" Error: missing command after pipe\n", 2);
		sh->last_exit_status = 1;
		return (false);
	}
	return (true);
}

bool	validate_all_redirections(char **tokens, t_shell *sh)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		if (is_token_control_char(tokens[i], CC_REDIR_IN)
			|| is_token_control_char(tokens[i], CC_HEREDOC))
		{
			if (!handle_input_redirection(tokens, &i, sh))
				return (false);
		}
		else if (is_token_control_char(tokens[i], CC_REDIR_OUT)
			|| is_token_control_char(tokens[i], CC_APPEND))
		{
			if (!handle_output_redirection(tokens, &i, sh))
				return (false);
		}
		else if (is_token_control_char(tokens[i], CC_PIPE))
		{
			if (!handle_pipe(tokens, i, sh))
				return (false);
		}
		i++;
	}
	return (true);
}

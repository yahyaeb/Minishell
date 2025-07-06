/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 19:22:54 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/15 01:36:10 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	validate_and_exec_command(char **argv, char **envp, t_shell *sh)
{
	if (!argv || !argv[0] || argv[0][0] == '\0')
		return (0);
	if (ft_strchr(argv[0], '/'))
		return (validate_direct_path(argv, sh));
	else
		return (validate_in_path(argv, envp, sh));
}

void	restore_quoted_spaces(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == CC_SPACE_IN_QUOTE)
			str[i] = ' ';
		i++;
	}
}

void	dispatch_command(t_cmd_type type, t_shell *sh, char **env)
{
	if (type == REDIR_ONLY)
		handle_redir_only(sh, env);
	else if (type == BASIC)
		handle_basic(sh);
	else if (type == PIPELINE || type == HERE_DOC)
	{
		handle_pipeline(sh, env);
	}
	else if (type == PIPELINE_WITH_RED)
	{
		sh->pipeline = ft_calloc(1, sizeof(t_pipeline));
		parse_and_build_pipeline(sh->pipeline, sh->input_args);
		run_pipeline_with_redir(sh->pipeline, env, sh);
		free_pipeline(sh->pipeline);
	}
	else
		sh->last_exit_status = ms_err("", "", SYNTAX_ERR, 2);
}

void	main_loop(t_shell *sh, char **env, char *line)
{
	t_cmd_type	type;

	while (1)
	{
		line = get_input(line);
		if (line == NULL)
			free_and_exit(sh, 0);
		if (line[0] == '\0')
			continue ;
		sh->input_args = normalize_input(line, sh);
		if (!sh->input_args)
			continue ;
		if (g_signal_status != 0)
		{
			sh->last_exit_status = g_signal_status;
			g_signal_status = 0;
		}
		if (loop_case_empty_str(sh) != 0)
			continue ;
		ft_interpret_env(sh);
		remove_empty_args(sh->input_args);
		type = classify_command(sh->input_args);
		dispatch_command(type, sh, env);
		free_args(sh->input_args);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_shell		sh;
	char		*line;

	line = NULL;
	if (argc != 1 || argv[1])
		return (-1);
	if (init_shell(&sh, env) != 0)
		return (-1);
	main_loop(&sh, env, line);
	free_memory(&sh);
	return (sh.last_exit_status);
}

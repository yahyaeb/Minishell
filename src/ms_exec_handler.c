/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_exec_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 23:24:52 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/17 04:55:31 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	handle_redir_only(t_shell *sh, char **env)
{
	t_pipeline	*pipeline;

	if (!validate_all_redirections(sh->input_args, sh))
		return ;
	pipeline = parse_redirection_only(sh->input_args);
	if (!pipeline || !pipeline->cmds || !pipeline->cmds[0].argv)
	{
		sh->last_exit_status = 1;
		ft_putstr_fd(" Invalid redirection command\n", 2);
		free_pipeline(pipeline);
		return ;
	}
	exec_with_redirection(pipeline, env, sh);
	free_pipeline(pipeline);
}

int	case_no_pipeline_needed(t_shell *sh, char **env_arr)
{
	if (!sh->input_args[0])
		return (2);
	if (is_builtin(sh->input_args[0]))
	{
		if ((ft_strcmp(sh->input_args[0], "exit") == 0)
			&& (ft_strslen(sh->input_args) <= 2))
			free_env_array(env_arr);
		sh->last_exit_status = process_input(sh);
		return (1);
	}
	if (!validate_all_redirections(sh->input_args, sh))
		return (1);
	if (sh->input_args[0][0] == '\0' || ft_strcmp(sh->input_args[0], ".") == 0
		|| ft_strcmp(sh->input_args[0], "..") == 0)
	{
		sh->last_exit_status = ms_err(
				"", sh->input_args[0], CMD_NOT_FOUND, 127);
		return (1);
	}
	if (ft_isalnum_x_str(sh->input_args[0], "!#$%&()*+,'\"-:;?@[\\]^{}~.") == 0)
	{
		if (validate_in_path(sh->input_args, env_arr, sh) == 1)
			return (1);
	}
	return (0);
}

void	handle_basic(t_shell *sh)
{
	char		**env_arr;

	if (basic_case_empty_var(sh) != 0)
		return ;
	ft_replace_all_chars(sh->input_args, CC_SPACE_IN_QUOTE, ' ');
	if (basic_case_empty_str(sh) != 0)
		return ;
	env_arr = env_list_to_array(sh->this_env);
	if (!env_arr)
		return ;
	if (case_no_pipeline_needed(sh, env_arr) != 0)
	{
		free_env_array(env_arr);
		return ;
	}
	if (case_redir_pipeline(sh, env_arr) != 0)
	{
		free_env_array(env_arr);
		return ;
	}
	free_env_array(env_arr);
}

bool	handle_heredoc_pipeline(t_pipeline *pipeline, char **env, t_shell *sh)
{
	int	status;

	if (pipeline->cmd_count < 1)
	{
		ft_printf("Error: heredoc requires at least one command\n");
		sh->last_exit_status = 1;
		return (false);
	}
	status = run_pipex_from_minshell(pipeline, env, sh->last_exit_status);
	if (status != 0)
	{
		sh->last_exit_status = status;
		return (false);
	}
	return (true);
}

void	handle_pipeline(t_shell *sh, char **env)
{
	t_pipeline	*pipeline;

	ft_replace_all_chars(sh->input_args, CC_SPACE_IN_QUOTE, ' ');
	replace_cc_empty_str(sh);
	pipeline = build_pipeline_from_tokens(sh->input_args);
	if (!pipeline)
	{
		sh->last_exit_status = 1;
		return ;
	}
	if (has_heredoc(pipeline))
	{
		if (!handle_heredoc_pipeline(pipeline, env, sh))
		{
			free_pipeline(pipeline);
			return ;
		}
	}
	else
		run_pipeline_basic_pipeline(pipeline, env, sh);
	free_pipeline(pipeline);
}

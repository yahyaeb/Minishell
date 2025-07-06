/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_input_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 23:27:22 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/15 12:30:55 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// Get the initial raw input from user
char	*get_input(char *line)
{
	if (line)
	{
		free(line);
		line = (char *) NULL;
	}
	line = readline(PROMPT_STYLE);
	if (line && *line)
	{
		add_history(line);
		if (rl_on_new_line() != -1)
			return (line);
	}
	else if (!line)
		return ((char *) NULL);
	return (line);
}

// Normalize the input and store the arguments for further use
char	**normalize_input(char *line, t_shell *sh)
{
	if (ft_strnopbrk(line, " \f\n\r\t\v") == NULL)
		return (NULL);
	sh->normalized_line = ft_normalize(line);
	if (!sh->normalized_line)
		return (NULL);
	sh->input_args = ft_split(sh->normalized_line, ' ');
	free(sh->normalized_line);
	sh->normalized_line = NULL;
	if (!sh->input_args)
		return (NULL);
	ft_replace_all_chars(sh->input_args, '|', CC_PIPE);
	if (!check_consecutive_redir(sh->input_args))
	{
		sh->last_exit_status = ms_err("", "", SYNTAX_ERR, 2);
		free_args(sh->input_args);
		sh->input_args = NULL;
		return (NULL);
	}
	return (sh->input_args);
}

//Should call the needed command and handle errors 
int	process_input(t_shell *sh)
{
	t_command	*cmd;
	int			res;

	res = 0;
	if (!sh->input_args || sh->input_args[0] == NULL)
		return (-1);
	ft_replace_all_chars(sh->input_args, CC_TRAILING_DOLLAR, '$');
	ft_replace_chars_in_str(sh->input_args[0], CC_SPACE_IN_QUOTE, ' ');
	cmd = is_registered_cmd(sh);
	if (cmd != NULL)
		sh->last_exit_status = cmd->func(sh);
	else
	{
		if ((ft_strcmp(sh->input_args[0], "\"\"") == 0
				|| ft_strcmp(sh->input_args[0], "\'\'") == 0)
			&& !sh->input_args[0][2])
			sh->last_exit_status = ms_err("", "", CMD_NOT_FOUND, 127);
		else if (sh->input_args[0][0] != '\0')
			handle_non_cmd(sh, res);
	}
	return (sh->last_exit_status);
}

int	handle_non_cmd(t_shell *sh, int res)
{
	char	**env_arr;

	res = are_args_stashable(sh->input_args);
	if (res == 0)
		res = stash_var(sh);
	else if (res != 0)
	{
		if (ft_strchr(sh->input_args[0], '/') != NULL)
		{
			sh->last_exit_status = handle_file_or_dir(sh);
			if (sh->last_exit_status != 0)
				return (sh->last_exit_status);
		}
		env_arr = env_list_to_array(sh->this_env);
		if (!env_arr)
			return (0);
		if (validate_in_path(sh->input_args, env_arr, sh))
		{
			free_env_array(env_arr);
			return (sh->last_exit_status);
		}
		case_redir_pipeline(sh, env_arr);
		free_env_array(env_arr);
	}
	return (res);
}

int	handle_file_or_dir(t_shell *sh)
{
	struct stat	st;

	if (ft_strchr(sh->input_args[0], '/'))
	{
		if (access(sh->input_args[0], F_OK) != 0)
			return (ms_err("", sh->input_args[0], NO_FILE_OR_DIR, 127));
		else
		{
			if (stat(sh->input_args[0], &st) != 0)
				return (ms_err("", sh->input_args[0], NO_FILE_OR_DIR, 127));
			if (S_ISDIR(st.st_mode))
				return (ms_err("", sh->input_args[0], CMD_IS_DIR, 126));
			if (access(sh->input_args[0], X_OK) != 0)
				return (ms_err("", sh->input_args[0], PERM_DENY, 126));
		}
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_input_manager_converter.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 16:34:25 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/12 18:33:19 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

char	**rejoin_env_array(t_list *cur, int count)
{
	char	**env_array;
	int		i;

	i = 0;
	env_array = malloc(sizeof(char *) * (count + 1));
	if (!env_array)
		return (NULL);
	while (cur)
	{
		env_array[i] = ft_strjoin_delim(((char **)cur->content)[0],
				((char **)cur->content)[1], "=");
		if (!env_array[i])
		{
			while (--i >= 0)
				free(env_array[i]);
			free(env_array);
			return (NULL);
		}
		cur = cur->next;
		i++;
	}
	env_array[i] = NULL;
	return (env_array);
}

char	**env_list_to_array(t_list *env_list)
{
	t_list	*cur;
	char	**env_array;
	int		count;

	count = 0;
	cur = env_list;
	while (cur)
	{
		count++;
		cur = cur->next;
	}
	env_array = rejoin_env_array(env_list, count);
	return (env_array);
}

void	free_env_array(char **env_array)
{
	int	i;

	if (!env_array)
		return ;
	i = 0;
	while (env_array[i])
	{
		free(env_array[i]);
		i++;
	}
	free(env_array);
}

int	case_redir_pipeline(t_shell *sh, char **env_arr)
{
	t_pipeline	*pipeline;

	pipeline = parse_redirection_only(sh->input_args);
	if (!pipeline || !pipeline->cmds || !pipeline->cmds[0].argv)
	{
		if (is_token_control_char(sh->input_args[0], CC_REDIR_OUT)
			|| is_token_control_char(sh->input_args[0], CC_APPEND)
			|| is_token_control_char(sh->input_args[0], CC_REDIR_IN)
			|| is_token_control_char(sh->input_args[0], CC_HEREDOC))
		{
			free_pipeline(pipeline);
			return (1);
		}
		sh->last_exit_status = ms_err(
				"", sh->input_args[0], CMD_NOT_FOUND, 127);
		free_pipeline(pipeline);
		return (1);
	}
	exec_with_redirection(pipeline, env_arr, sh);
	free_pipeline(pipeline);
	return (0);
}

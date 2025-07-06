/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_commands_manager.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 18:25:28 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/05 11:53:36 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	init_cmds(t_shell *sh) // could loop from a file instead
{
	int	res;
	int	i;

	ft_init_two_ints(0, &res, &i);
	sh->cmds = malloc(sizeof(t_command) * (NB_CMDS + 1));
	if (!sh->cmds)
		return (-1);
	sh->cmds[0] = register_cmd("exit", cmd_exit, "Exit minishell");
	sh->cmds[1] = register_cmd("pwd", cmd_pwd, "Print working directory");
	sh->cmds[2] = register_cmd("cd", cmd_cd, "Change working directory");
	sh->cmds[3] = register_cmd("env", cmd_env, "Display env variables");
	sh->cmds[4] = register_cmd("export", cmd_export,
			"Set the export attribute for variables");
	sh->cmds[5] = register_cmd("unset", cmd_unset,
			"Unset values and attributes of variables and functions");
	sh->cmds[6] = register_cmd("echo", cmd_echo, "Display a line of text");
	i = 0;
	while (i < NB_CMDS)
	{
		if (sh->cmds[i] == NULL)
			res = -1;
		i++;
	}
	sh->cmds[7] = NULL;
	return (res);
}

t_command	*register_cmd(char *name, void *func, char *doc)
{
	t_command	*cmd;
	size_t		name_len;
	size_t		doc_len;

	cmd = malloc(sizeof(t_command));
	if (!cmd)
		return (NULL);
	name_len = ft_strlen(name);
	doc_len = ft_strlen(doc);
	cmd->name = malloc(sizeof(char) * (name_len + 1));
	if (!cmd->name)
		return (NULL);
	cmd->doc = malloc(sizeof(char) * (doc_len + 1));
	if (!cmd->doc)
		return (NULL);
	ft_strlcpy(cmd->name, name, name_len + 1);
	cmd->func = func;
	ft_strlcpy(cmd->doc, doc, doc_len + 1);
	return (cmd);
}

t_command	*is_registered_cmd(t_shell *sh)
{
	int		i;
	int		j;
	size_t	nb_args;

	i = 0;
	j = 0;
	nb_args = ft_strslen(sh->input_args);
	while ((size_t)i < nb_args && (sh->input_args[i][0] == '\0'))
	{
		if (sh->input_args[i][0] == '\0')
			i++;
		if (!sh->input_args[i])
			return (NULL);
	}
	while (sh->cmds[j] != NULL)
	{
		if (ft_strcmp(sh->input_args[i], sh->cmds[j]->name) == 0)
			return (sh->cmds[j]);
		else
			j++;
	}
	return (NULL);
}

void	cleanup_commands(t_shell *sh)
{
	int	i;

	if (!sh || !sh->cmds)
		return ;
	i = 0;
	while (i < NB_CMDS)
	{
		if (sh->cmds[i])
		{
			free(sh->cmds[i]->name);
			free(sh->cmds[i]->doc);
			free(sh->cmds[i]);
		}
		i++;
	}
	free(sh->cmds);
	sh->cmds = NULL;
}

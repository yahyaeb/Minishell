/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yahya_ms_to_pipex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:07:30 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/11 11:09:28 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	append_token_to_argvs(t_pipeline *p, char *token, int current_cmd)
{
	int	arg_count;

	arg_count = 0;
	while (p->cmds[current_cmd].argv[arg_count])
		arg_count++;
	p->cmds[current_cmd].argv[arg_count] = ft_strdup(token);
	p->cmds[current_cmd].argv[arg_count + 1] = NULL;
}

static t_pipeline	*init_pipeline(char **tokens)
{
	t_pipeline	*p;

	p = ft_calloc(1, sizeof(t_pipeline));
	if (!p)
		return (NULL);
	p->cmd_count = count_cmds(tokens);
	p->cmds = ft_calloc(p->cmd_count, sizeof(t_commands));
	if (!p->cmds)
	{
		free(p);
		return (NULL);
	}
	return (p);
}

t_pipeline	*build_pipeline_from_tokens(char **tokens)
{
	int			i;
	t_pipeline	*p;
	int			current_cmd;

	i = 0;
	p = init_pipeline(tokens);
	if (!p)
		return (NULL);
	current_cmd = 0;
	while (tokens[i])
	{
		if (handle_redirection_tokens(tokens, &i, p, current_cmd))
			continue ;
		if (handle_pipe_token(tokens, &i, &current_cmd))
			continue ;
		if (init_argv_if_needed(p, tokens, i, current_cmd))
			return (NULL);
		if (p->cmds[current_cmd].argv)
			append_token_to_argvs(p, tokens[i], current_cmd);
		i++;
	}
	return (p);
}

void	free_cmds_files_and_limiter(t_commands *cmd)
{
	if (cmd->infile != NULL)
		free(cmd->infile);
	if (cmd->outfile != NULL)
		free(cmd->outfile);
	if (cmd->limiter != NULL)
		free(cmd->limiter);
}

void	free_pipeline(t_pipeline *p)
{
	int	i;
	int	j;

	i = 0;
	if (!p)
		return ;
	while (i < p->cmd_count)
	{
		free_cmds_files_and_limiter(&p->cmds[i]);
		if (p->cmds[i].argv)
		{
			j = 0;
			while (p->cmds[i].argv[j])
			{
				free(p->cmds[i].argv[j]);
				j++;
			}
			free(p->cmds[i].argv);
		}
		i++;
	}
	free(p->cmds);
	free(p);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_ye.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 13:57:41 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/05 09:44:12 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

#include "../inc/minishell.h"

void	free_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
	{
		free(tokens[i]);
		i++;
	}
	free(tokens);
}

static void	process_command_segment(t_pipeline *pipeline,
	char **tokens, t_parse_utils *build)
{
	char	**cmd_tokens;

	cmd_tokens = extract_tokens(tokens, build->start, build->i);
	pipeline->cmds[build->cmd_index] = parse_command(cmd_tokens);
	(build->cmd_index)++;
	free_tokens(cmd_tokens);
}

void	safe_process_command_segment(t_pipeline *pipeline,
	char **tokens, t_parse_utils *build)
{
	if (build->cmd_index >= build->num_cmds)
		exit(1);
	process_command_segment(pipeline, tokens, build);
}

void	parse_and_build_pipeline(t_pipeline *pipeline, char **tokens)
{
	t_parse_utils	build;

	build.pipe_token[0] = CC_PIPE;
	build.pipe_token[1] = '\0';
	build.i = 0;
	build.start = 0;
	build.cmd_index = 0;
	build.num_cmds = count_pipes(tokens) + 1;
	pipeline->cmd_count = build.num_cmds;
	pipeline->cmds = ft_calloc(build.num_cmds, sizeof(t_commands));
	if (!pipeline->cmds)
		exit(1);
	while (tokens[build.i])
	{
		if (ft_strcmp(tokens[build.i], build.pipe_token) == 0)
		{
			safe_process_command_segment(pipeline, tokens, &build);
			build.start = build.i + 1;
		}
		build.i++;
	}
	if (build.cmd_index >= build.num_cmds)
		exit(1);
	process_command_segment(pipeline, tokens, &build);
}

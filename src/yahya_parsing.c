/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   yahya_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 12:04:47 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/05 07:51:58 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	**extract_tokens(char **tokens, int start, int end)
{
	int			len;
	char		**result;
	int			i;

	i = 0;
	len = end - start;
	result = malloc(sizeof(char *) * (len + 1));
	while (i < len)
	{
		result[i] = ft_strdup(tokens[start + i]);
		i++;
	}
	result[len] = NULL;
	return (result);
}

bool	handle_redir_in_parsing(t_commands *cmd,
			t_parse_state *fd, char **tokens, int *i)
{
	fd->test_fd = open(tokens[*i + 1], O_RDONLY);
	if (fd->test_fd < 0)
	{
		perror(tokens[*i + 1]);
		free(cmd->argv);
		cmd->argv = NULL;
		return (false);
	}
	close(fd->test_fd);
	free(cmd->infile);
	cmd->infile = ft_strdup(tokens[++(*i)]);
	return (true);
}

t_commands	parse_command(char **tokens)
{
	t_commands		cmd;
	t_parse_state	fd;

	memset(&fd, 0, sizeof(t_parse_state));
	memset(&cmd, 0, sizeof(t_commands));
	cmd.argv = malloc(sizeof(char *) * (count_args(tokens) + 1));
	if (!cmd.argv)
	{
		cmd.infile = NULL;
		cmd.outfile = NULL;
		return (cmd);
	}
	if (!parse_tokens_loop(&cmd, &fd, tokens))
		return (cmd);
	if (fd.last_outfile)
	{
		free(cmd.outfile);
		cmd.outfile = fd.last_outfile;
		cmd.append = fd.last_append;
	}
	return (cmd);
}

void	free_command(t_commands *cmd)
{
	int	i;

	if (cmd->argv)
	{
		i = 0;
		while (cmd->argv[i])
		{
			free(cmd->argv[i]);
			i++;
		}
		free(cmd->argv);
	}
	free(cmd->infile);
	free(cmd->outfile);
}

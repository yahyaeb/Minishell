/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_handle_pipe_with_red.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 18:07:30 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/01 07:15:47 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	open_infile(t_commands *cmd, t_shell *sh)
{
	int	fd;

	if (!cmd->infile)
		return (-1);
	fd = open(cmd->infile, O_RDONLY);
	if (fd < 0)
	{
		sh->last_exit_status = 1;
		perror(cmd->infile);
		return (-1);
	}
	return (fd);
}

static int	open_outfile(t_commands *cmd, t_shell *sh)
{
	int	fd;
	int	flags;

	if (!cmd->outfile)
		return (-1);
	flags = O_WRONLY | O_CREAT;
	if (cmd->append)
		flags |= O_APPEND;
	else
		flags |= O_TRUNC;
	fd = open(cmd->outfile, flags, 0644);
	if (fd < 0)
	{
		sh->last_exit_status = 1;
		perror(cmd->outfile);
		return (-1);
	}
	return (fd);
}

int	open_redirection_fds_mixed(t_commands *cmd,
	int *in_fd, int *out_fd, t_shell *sh)
{
	*in_fd = open_infile(cmd, sh);
	if (*in_fd < 0 && cmd->infile)
		return (-1);
	*out_fd = open_outfile(cmd, sh);
	if (*out_fd < 0 && cmd->outfile)
	{
		if (*in_fd != -1)
			close(*in_fd);
		return (-1);
	}
	return (0);
}

void	handle_exit_status(int status, t_shell *sh)
{
	int	sig;

	if (WIFEXITED(status))
		sh->last_exit_status = WEXITSTATUS(status);
	else if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (sig == SIGINT)
		{
			sh->last_exit_status = 130;
			printf("\n");
		}
		else if (sig == SIGQUIT)
		{
			sh->last_exit_status = 131;
			printf("Quit (core dumped)\n");
		}
		else
			sh->last_exit_status = 128 + sig;
	}
}

void	wait_for_pipeline(t_pipeline *p, pid_t last_pid, t_shell *sh)
{
	int		i;
	int		status;
	pid_t	wpid;

	i = 0;
	while (i < p->cmd_count)
	{
		wpid = wait(&status);
		if (wpid == -1)
			break ;
		if (wpid == last_pid)
			handle_exit_status(status, sh);
		i++;
	}
}

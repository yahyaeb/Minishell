/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_cases.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 18:14:08 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/06 18:19:17 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_heredoc_error(t_pipeline *pipeline)
{
	if (handle_heredoc(pipeline->cmds->limiter) != 0)
	{
		perror("Error: here_doc failed");
		return (1);
	}
	return (0);
}

int	handle_pipex_in_fd_error(t_pipex pipex)
{
	if (pipex.in_fd < 0)
	{
		perror("open .heredoc_tmp");
		return (1);
	}
	return (0);
}

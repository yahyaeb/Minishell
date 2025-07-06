/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_debug_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 14:29:10 by mmalie            #+#    #+#             */
/*   Updated: 2025/05/11 21:52:22 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

// Display the content of strs
void	ft_show_strs(char **strs, char *debug_msg)
{
	int	i;

	i = 0;
	while (strs[i] != NULL)
	{
		printf("%s: strs[%d]: %s\n", debug_msg, i, strs[i]);
		i++;
	}
}

// Save a line on returning by sending a message to a fd
int	ft_ret(int return_val, char *msg, int fd)
{
	ft_putstr_fd(msg, fd);
	return (return_val);
}

int	ms_err(char *cmd_name, char *arg, char *err_msg, int return_val)
{
	char	*final_msg;
	char	*first_part;
	char	*second_part;

	first_part = ft_strjoin(SHELL_NAME, cmd_name);
	if (!first_part)
		return (return_val);
	second_part = ft_strjoin(arg, err_msg);
	if (!second_part)
	{
		free(first_part);
		return (return_val);
	}
	final_msg = ft_strjoin(first_part, second_part);
	free(first_part);
	free(second_part);
	if (!final_msg)
		return (return_val);
	ft_putstr_fd(final_msg, STDERR);
	free(final_msg);
	return (return_val);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_and_basic_cases.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 01:28:01 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/15 01:35:01 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	loop_case_empty_str(t_shell *sh)
{
	if (!sh->input_args[0])
	{
		sh->last_exit_status = ms_err("", "", CMD_NOT_FOUND, 127);
		free_args(sh->input_args);
		return (1);
	}
	return (0);
}

int	basic_case_empty_str(t_shell *sh)
{
	if (ft_strcmp(sh->input_args[0], "\"\"") == 0
		|| ft_strcmp(sh->input_args[0], "\'\'") == 0)
	{
		sh->last_exit_status = ms_err(
				"", "", CMD_NOT_FOUND, 127);
		return (1);
	}
	return (0);
}

int	basic_case_empty_var(t_shell *sh)
{
	if (!sh->input_args[0])
	{
		sh->last_exit_status = 0;
		return (1);
	}
	return (0);
}

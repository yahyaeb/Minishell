/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_here_doc_env.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 10:22:18 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/17 08:46:48 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	get_var_bounds(const char *str, int start, int *end)
{
	int	i;

	i = start;
	if (!str[i] || (!ft_isalpha(str[i]) && str[i] != '_'))
		return (0);
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	*end = i;
	return (1);
}

static char	*replace_var(char *str, int start, int end, const char *value)
{
	char	*prefix;
	char	*suffix;
	char	*temp;
	char	*result;

	prefix = ft_substr(str, 0, start);
	suffix = ft_strdup(str + end);
	if (value)
		temp = ft_strjoin(prefix, value);
	else
		temp = ft_strjoin(prefix, "");
	result = ft_strjoin(temp, suffix);
	free(prefix);
	free(suffix);
	free(temp);
	free(str);
	return (result);
}

static char	*handle_env_var(char *str, int *index)
{
	int		start;
	int		end;
	char	*var_name;
	char	*var_value;
	char	*new_str;

	start = *index + 1;
	if (!get_var_bounds(str, start, &end))
		return (str);
	var_name = ft_substr(str, start, end - start);
	if (!var_name)
		return (str);
	var_value = getenv(var_name);
	free(var_name);
	new_str = replace_var(str, *index, end, var_value);
	if (var_value)
		*index += ft_strlen(var_value);
	else
		*index += 0;
	return (new_str);
}

static char	*handle_exit_status_var(char *str, int *index, int exit_status)
{
	char	*exit_status_str;
	char	*new_str;

	exit_status_str = ft_itoa(exit_status);
	if (!exit_status_str)
		return (str);
	new_str = replace_var(str, *index, *index + 2, exit_status_str);
	*index += ft_strlen(exit_status_str);
	free(exit_status_str);
	return (new_str);
}

char	*expand_env_vars(const char *line, int exit_status)
{
	char	*result;
	int		i;

	i = 0;
	result = ft_strdup(line);
	if (!result)
		return (NULL);
	while (result[i])
	{
		if (result[i] == '$' && result[i + 1] == '?')
			result = handle_exit_status_var(result, &i, exit_status);
		else if (result[i] == '$' && result[i + 1]
			&& (ft_isalnum(result[i + 1]) || result[i + 1] == '_'))
			result = handle_env_var(result, &i);
		else
			i++;
	}
	return (result);
}

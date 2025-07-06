/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_normalize_add_spaces_utils.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 20:05:11 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/11 13:03:46 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

void	copy_with_spaces(char *new_str, const char *str, char special)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == special)
			increase_str(new_str, special, &j);
		else
			new_str[j++] = str[i];
		i++;
	}
	new_str[j] = '\0';
}

char	*ft_add_spaces_around(char *str, char special)
{
	int		len;
	int		extra;
	char	*new_str;

	extra = count_extra_spaces(str, special);
	len = ft_strlen(str);
	new_str = malloc(len + extra + 1);
	if (!new_str)
		return (NULL);
	copy_with_spaces(new_str, str, special);
	return (new_str);
}

int	count_substring_occurrences(const char *line, const char *str, int op_len)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (strncmp(&line[i], str, op_len) == 0)
			count++;
		i++;
	}
	return (count);
}

void	copy_with_spaces_around(char *result,
			const char *line, const char *str, int op_len)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	j = 0;
	while (line[i])
	{
		if (strncmp(&line[i], str, op_len) == 0)
		{
			result[j++] = ' ';
			k = 0;
			while (k < op_len)
				result[j++] = str[k++];
			result[j++] = ' ';
			i += op_len;
		}
		else
			result[j++] = line[i++];
	}
	result[j] = '\0';
}

char	*ft_add_spaces_around_str(const char *line, const char *str)
{
	int		op_len;
	char	*result;
	int		count;
	int		len;
	char	*new_line;

	op_len = strlen(str);
	count = count_substring_occurrences(line, str, op_len);
	len = strlen(line);
	if (count == 0)
	{
		new_line = ft_strdup(line);
		return (new_line);
	}
	result = malloc(len + count * 2 + 1);
	if (!result)
		return (NULL);
	copy_with_spaces_around(result, line, str, op_len);
	return (result);
}

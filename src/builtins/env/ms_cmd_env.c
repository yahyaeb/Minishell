/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_cmd_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 13:01:09 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/17 16:40:40 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../inc/minishell.h"

int	cmd_env(t_shell *sh)
{
	t_list	*cur_node;

	cur_node = sh->this_env;
	while (cur_node != NULL)
	{
		if (((char **)cur_node->content)[1] != NULL)
		{
			printf("%s=%s\n",
				((char **)cur_node->content)[0],
				((char **)cur_node->content)[1]);
		}
		else
			printf("%s=%s\n", ((char **)cur_node->content)[0], "");
		cur_node = cur_node->next;
	}
	return (0);
}

void	sort_env_array(char **env_array, int count)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	while (i < count - 1)
	{
		j = i + 1;
		while (j < count)
		{
			if (ft_strcmp(env_array[i], env_array[j]) > 0)
			{
				temp = env_array[i];
				env_array[i] = env_array[j];
				env_array[j] = temp;
			}
			j++;
		}
		i++;
	}
}

void	print_sorted_export(char **env_array)
{
	int		i;
	char	*equal_sign;

	i = 0;
	while (env_array[i])
	{
		equal_sign = ft_strchr(env_array[i], '=');
		if (equal_sign)
		{
			*equal_sign = '\0';
			printf("declare -x %s=\"%s\"\n", env_array[i], equal_sign + 1);
			*equal_sign = '=';
		}
		else
			printf("declare -x %s\n", env_array[i]);
		i++;
	}
}

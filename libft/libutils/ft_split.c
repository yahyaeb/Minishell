/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:57:39 by mmalie            #+#    #+#             */
/*   Updated: 2025/04/14 15:40:23 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Splits a string into a memory allocated array of substrings, 
 * separated by a specified delimiter.
 */
char		**ft_split(char const *s, char c);
static int	count_tokens(char const *s, char delim);
static char	**store_tokens(char const *s, char delim, char **array);
static char	**malloc_storage(char **array, int i, int token_len);

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		nb_tokens;

	array = NULL;
	nb_tokens = count_tokens(s, c);
	array = (char **)malloc((nb_tokens + 1) * sizeof(char *));
	if (array == NULL)
		return (NULL);
	array = store_tokens(s, c, array);
	if (array == NULL)
		return (NULL);
	return (array);
}

static int	count_tokens(char const *s, char delim)
{
	int	nb_tokens;
	int	i;

	nb_tokens = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == delim && s[i] != '\0')
			i++;
		if (s[i] != delim && s[i] != '\0')
		{
			nb_tokens++;
			while (s[i] != delim && s[i] != '\0')
				i++;
		}
	}
	return (nb_tokens);
}

static char	**store_tokens(char const *s, char delim, char **array)
{
	int	i;
	int	j;
	int	token_len;

	i = 0;
	j = 0;
	while (s[j] != '\0')
	{
		while (s[j] == delim && s[j] != '\0')
			j++;
		if (s[j] != delim && s[j] != '\0')
		{
			token_len = 0;
			while (s[j + token_len] != delim && s[j + token_len] != '\0')
				token_len++;
			array = malloc_storage(array, i, token_len);
			if (array == NULL)
				return (NULL);
			ft_strlcpy(array[i], &s[j], token_len + 1);
			j += token_len;
			i++;
		}
	}
	array[i] = NULL;
	return (array);
}

static char	**malloc_storage(char **array, int i, int token_len)
{
	int	j;

	array[i] = (char *)malloc((token_len + 1) * sizeof(char));
	if (array[i] == NULL)
	{
		j = 0;
		while (j < i)
		{
			free(array[j]);
			j++;
		}
		free(array);
		return (NULL);
	}
	return (array);
}

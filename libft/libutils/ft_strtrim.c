/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:36:00 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:33:40 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Trims the characters of a given set from the beginning and end of a string.
*/
char		*ft_strtrim(char const *s1, char const *set);
static int	map(char const *s1, int s1_len, char const *set, int *start_i);
static int	is_in_set(char c, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed_s;
	int		trim_len;
	int		start_i;
	int		s1_len;
	int		set_len;

	if (!s1)
		return (NULL);
	s1_len = ft_strlen(s1);
	set_len = ft_strlen(set);
	start_i = 0;
	if (set_len == 0)
		trim_len = s1_len;
	if (s1_len == 0)
		trim_len = 0;
	if (s1_len != 0 && set_len != 0)
		trim_len = map(s1, s1_len, set, &start_i);
	trimmed_s = (char *)malloc(sizeof(char) * (trim_len + 1));
	if (trimmed_s == NULL)
		return (NULL);
	if (trim_len > 0)
		ft_strlcpy(trimmed_s, &s1[start_i], trim_len + 1);
	else
		trimmed_s[0] = '\0';
	return (trimmed_s);
}

static int	map(char const *s1, int s1_len, char const *set, int *start_i)
{
	int	trim_len;
	int	end_i;

	trim_len = s1_len;
	end_i = s1_len - 1;
	while (*start_i < s1_len && is_in_set(s1[*start_i], set) == 1)
	{
		trim_len--;
		(*start_i)++;
	}
	while (end_i >= *start_i && is_in_set(s1[end_i], set))
	{
		trim_len--;
		end_i--;
	}
	return (trim_len);
}

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

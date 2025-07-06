/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 09:33:12 by mmalie            #+#    #+#             */
/*   Updated: 2025/02/09 10:00:47 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_gnl(int fd)
{
	char		*buf;
	static char	*stash = NULL;
	char		*cursor;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (stash)
			clean_stash(&stash);
		return (NULL);
	}
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	cursor = NULL;
	if (stash != NULL && *stash != '\0')
		cursor = ft_strchr(stash, '\n');
	stash = read_and_stash(fd, &buf, &stash, &cursor);
	free(buf);
	if (!stash)
		return (NULL);
	return (seize_line(&stash, cursor));
}

char	*read_and_stash(int fd, char **buf, char **stash, char **cursor)
{
	int	b_read;

	if (!buf || !*buf)
		return (NULL);
	while (*cursor == NULL)
	{
		b_read = read(fd, *buf, BUFFER_SIZE);
		if (b_read == -1)
		{
			if (*stash)
				clean_stash(stash);
			return (NULL);
		}
		if (b_read == 0)
			break ;
		(*buf)[b_read] = '\0';
		*stash = stash_manager(*stash, *buf, b_read);
		if (!*stash)
			return (NULL);
		*cursor = ft_strchr(*stash, '\n');
	}
	return (*stash);
}

char	*stash_manager(char *stash, char *buf, size_t b_read)
{
	char	*new_stash;
	size_t	stash_len;

	if (!buf)
		return (NULL);
	stash_len = 0;
	if (stash)
		stash_len = ft_strlen(stash);
	new_stash = malloc(sizeof(char) * (stash_len + b_read + 1));
	if (!new_stash)
		return (NULL);
	if (stash)
	{
		ft_strlcpy(new_stash, stash, stash_len + 1);
		free(stash);
	}
	if (buf)
		ft_strlcpy(new_stash + stash_len, buf, b_read + 1);
	return (new_stash);
}

char	*seize_line(char **stash, char *cursor)
{
	int		chunk_len;
	char	*next_line;
	int		leftover;

	if (!*stash && !**stash)
		return (NULL);
	next_line = NULL;
	if (cursor != NULL)
	{
		chunk_len = (cursor - *stash + 1);
		next_line = malloc(sizeof(char) * (chunk_len + 1));
		if (!next_line)
			return (NULL);
		ft_strlcpy(next_line, *stash, chunk_len + 1);
		leftover = ft_strlen(*stash) - chunk_len;
		if (leftover > 0)
			ft_strlcpy(*stash, *stash + chunk_len, leftover + 1);
		else
			clean_stash(stash);
	}
	else
		next_line = seize_eof(&next_line, stash);
	if (!next_line)
		return (NULL);
	return (next_line);
}

char	*seize_eof(char **next_line, char **stash)
{
	int	chunk_len;

	if (!*stash && !**stash)
		return (NULL);
	chunk_len = ft_strlen(*stash);
	*next_line = malloc(sizeof(char) * (chunk_len + 1));
	if (!*next_line)
		return (NULL);
	ft_strlcpy(*next_line, *stash, chunk_len + 1);
	clean_stash(stash);
	free(stash);
	return (*next_line);
}

/* GNL launcher. Kept for debugging and expansion.*/
/* #include <stdio.h>
int	main(void)
{
	char	*next_line;
	int		fd;
	int		i;

int	main(void)
{
	char	*next_line;
	int		fd;
	int		i;

	fd = open("test.txt", O_RDONLY);
	i = 0;
	while (1)
	{
		i++;
		printf("=== ITERATION %d === \n", i);
		next_line = ft_gnl(fd);
		if (next_line == NULL)
		{
			printf("End of file!\n");
			break ;
		}
		else
		{
			printf("Final next_line: *%s*\n", next_line);
			free(next_line);
		}
	}
	return (0);
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libgnl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:25:28 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/10 14:18:47 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBGNL_H
# define LIBGNL_H

// Defines buffer size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

/* STANDARD LIBRARIES */
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h> 
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>

/* LIBGNL - Get Next Line */
char	*ft_gnl(int fd);
char	*read_and_stash(int fd, char **buf, char **stash, char **cursor);
char	*stash_manager(char *stash, char *buf, size_t b_read);
char	*seize_line(char **stash, char *cursor);
char	*seize_eof(char **next_line, char **stash);
void	clean_stash(char **stash);

#endif

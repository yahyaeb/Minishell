/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libutils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:25:28 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/14 22:13:48 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUTILS_H
# define LIBUTILS_H

/* STANDARD LIBRARIES */
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h> 
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>

/* LIBUTILS */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_open_file(char *fpath, char *access_mode, char *error_msg);
int		ft_read_line(int fd, char **line, char *error_msg);
int		ft_abs_int(int nb);
void	ft_init_ints(int init_value, int count, ...);
void	ft_init_two_ints(int init_value, int *int_1, int *int_2);
void	ft_init_three_ints(int init_value, int *int_1, int *int_2, int *int_3);
void	ft_init_two_size_t(size_t init_value, size_t *nb_1, size_t *nb_2);
int		ft_count_char(char *str, char c);

#endif

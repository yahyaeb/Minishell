/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:25:28 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/10 14:18:47 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H

/* STANDARD LIBRARIES */
# include <stdlib.h>
# include <stddef.h>
# include <stdint.h> 
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdio.h>

/* LIBPRINTF */
int			ft_printf(const char *fmt, ...);
// Managing conversion specificators
const char	*ft_spec_conv(const char *fmt, va_list args, size_t *b_writ);
void		conv_num(const char *fmt, va_list args, char *flg, size_t *b_writ);
void		conv_hex(const char *fmt, va_list args, char *flg, size_t *b_writ);
void		conv_txt(const char *fmt, va_list args, size_t *b_writ);
// Conversion to hexadecimal
char		*ft_itohex(char *dest, unsigned long nb, char style);
void		hex_set_case(char style, int *case_var);
char		*hex_handle_zero(char *hex_value, char style);
char		*hex_format_string(int i, char *hex_value, char style);
// For outputing and counting written bytes
size_t		ft_putchar_fd_count(char c, int fd);
size_t		ft_putstr_fd_count(char *s, int fd);
size_t		ft_putnbr_fd_count(int n, int fd);
size_t		ft_put_ui_fd_count(unsigned int n, int fd);

#endif

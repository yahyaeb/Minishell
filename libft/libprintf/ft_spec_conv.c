/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:22:43 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/19 12:04:48 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * This set of functions analyses ft_printf's args and outputs them depending
 * on the flags (#, <space> or +). While writing, it will update the number
 * of bytes written through the b_writ pointer.
 *
*/

const char	*ft_spec_conv(const char *fmt, va_list args, size_t *b_writ)
{
	const char	*next_i;
	char		flg[10];

	ft_memset(flg, 0, sizeof(flg));
	next_i = fmt + 1;
	while (*next_i == '#' || *next_i == ' ' || *next_i == '+')
	{
		if (*next_i == '#')
			flg[0] = '#';
		if (*next_i == ' ')
			flg[1] = ' ';
		if (*next_i == '+')
			flg[2] = '+';
		next_i++;
	}
	if (*next_i == 'd' || *next_i == 'i' || *next_i == 'u')
		conv_num(next_i, args, flg, b_writ);
	else if (*next_i == 'p' || *next_i == 'x' || *next_i == 'X')
		conv_hex(next_i, args, flg, b_writ);
	else if (*next_i == 's' || *next_i == 'c' || *next_i == '%')
		conv_txt(next_i, args, b_writ);
	return (next_i);
}

void	conv_num(const char *next_i, va_list args, char *flg, size_t *b_writ)
{
	int				cur_arg_int;
	unsigned int	cur_arg_unsigned_int;

	cur_arg_int = 0;
	cur_arg_unsigned_int = 0;
	if (*next_i == 'i' || *next_i == 'd')
	{
		cur_arg_int = va_arg(args, int);
		if (flg[1] == ' ' && cur_arg_int >= 0 && flg[2] != '+')
			*b_writ += ft_putchar_fd_count(' ', 1);
		else if (flg[2] == '+' && cur_arg_int >= 0)
			*b_writ += ft_putchar_fd_count('+', 1);
		*b_writ += ft_putnbr_fd_count(cur_arg_int, 1);
	}
	else if (*next_i == 'u')
	{
		cur_arg_unsigned_int = (unsigned int)va_arg(args, unsigned int);
		*b_writ += ft_put_ui_fd_count(cur_arg_unsigned_int, 1);
	}
}

void	conv_hex(const char *next_i, va_list args, char *flg, size_t *b_writ)
{
	unsigned long	cur_arg_long;
	unsigned int	cur_arg_int;
	char			*hex_value;

	hex_value = NULL;
	if (*next_i == 'p')
	{
		cur_arg_long = (unsigned long)va_arg(args, unsigned long);
		hex_value = ft_itohex(hex_value, cur_arg_long, 'p');
		*b_writ += ft_putstr_fd_count(hex_value, 1);
	}
	else if (*next_i == 'x' || *next_i == 'X')
	{
		cur_arg_int = (unsigned int)va_arg(args, unsigned int);
		if (flg[0] == '#' && *next_i == 'x')
			hex_value = ft_itohex(hex_value, cur_arg_int, 't');
		else if (flg[0] == '#' && *next_i == 'X')
			hex_value = ft_itohex(hex_value, cur_arg_int, 'b');
		else
			hex_value = ft_itohex(hex_value, cur_arg_int, *next_i);
		*b_writ += ft_putstr_fd_count(hex_value, 1);
	}
	if (hex_value != NULL)
		free(hex_value);
}

void	conv_txt(const char *next_i, va_list args, size_t *b_writ)
{
	int		cur_arg_int;
	char	*cur_arg_str;

	cur_arg_int = 0;
	cur_arg_str = NULL;
	if (*next_i == 'c')
	{
		cur_arg_int = va_arg(args, int);
		*b_writ += ft_putchar_fd_count((char)cur_arg_int, 1);
	}
	else if (*next_i == 's')
	{
		cur_arg_str = va_arg(args, char *);
		if (cur_arg_str != NULL)
			*b_writ += ft_putstr_fd_count(cur_arg_str, 1);
		else
			*b_writ += ft_putstr_fd_count("(null)", 1);
	}
	else if (*next_i == '%')
	{
		*b_writ += ft_putchar_fd_count('%', 1);
	}
}

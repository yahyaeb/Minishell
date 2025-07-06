/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:22:43 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/19 11:55:05 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * This set of functions converts an unsigned long number to hexadecimal.
 * A style parameter (input as a char) defines how the output looks like:
 *
 * 'X': without 0X & uppercase A to F
 * 'x': without 0x & lowercase A to F
 * '#': 0X/0x prefix & uppercase/lowercase A to F (with 'X' or 'x')
 * 'p': with 0x & lowercase A to F ("pointer notation")
*/

char	*ft_itohex(char *dest, unsigned long nb, char style)
{
	char			hex_value[20];
	unsigned long	quotient;
	unsigned long	remainder;
	int				i;
	int				case_var;

	ft_memset(hex_value, 0, sizeof(hex_value));
	if (nb == 0)
		return (hex_handle_zero(hex_value, style));
	hex_set_case(style, &case_var);
	quotient = nb;
	i = 0;
	while (quotient != 0)
	{
		remainder = quotient % 16;
		if (remainder >= 10 && remainder <= 15)
			hex_value[i] = (char)remainder + case_var;
		else if (remainder < 10)
			hex_value[i] = (char)remainder + '0';
		quotient = quotient / 16;
		i++;
	}
	hex_format_string(i, hex_value, style);
	dest = ft_strdup(hex_value);
	return (dest);
}

void	hex_set_case(char style, int *case_var)
{
	if (!case_var || !style)
		return ;
	if (style == 'X' || style == 'b')
		*case_var = 'A' - 10;
	else if (style == 'p' || style == 'x' || style == 't')
		*case_var = 'a' - 10;
}

char	*hex_handle_zero(char *hex_value, char style)
{
	char	*dest;
	int		i;

	i = 0;
	hex_value[i] = '0';
	if (style == 'p')
	{
		hex_value[i] = '(';
		hex_value[i + 1] = 'n';
		hex_value[i + 2] = 'i';
		hex_value[i + 3] = 'l';
		hex_value[i + 4] = ')';
		i = 4;
	}
	hex_value[i + 1] = '\0';
	dest = ft_strdup(hex_value);
	return (dest);
}

char	*hex_format_string(int i, char *hex_value, char style)
{
	if (style == 'p' || style == 't' || style == 'b')
	{
		if (style == 'p' || style == 't')
			hex_value[i] = 'x';
		else
			hex_value[i] = 'X';
		hex_value[i + 1] = '0';
	}
	ft_strrev(hex_value);
	hex_value[i + 2] = '\0';
	return (hex_value);
}

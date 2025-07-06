/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 12:22:43 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/19 12:06:08 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Custom implementation of print_f().
 *
 * This version handles the following conversions and writes to stdout:
 *	%c: Prints a single character.
 *	%s: Prints a string (as defined by the common C convention).
 *	%p: Prints the void * pointer argument in hexadecimal (as %#x or %#lx) 
 *	%d: Prints a decimal (base 10) number.
 *	%i: Prints an integer in base 10.
 *	%u: Prints an unsigned decimal (base 10) number.
 *	%x: Prints a number in hexadecimal (base 16) lowercase format.
 *	%X: Prints a number in hexadecimal (base 16) uppercase format.
 *	%%: Prints a percent sign.
*/

int	ft_printf(const char *fmt, ...)
{
	va_list	args;
	size_t	b_writ;

	va_start(args, fmt);
	if (!fmt)
		return (-1);
	b_writ = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			fmt = ft_spec_conv(fmt, args, &b_writ);
		}
		else
		{
			write(1, &(*fmt), 1);
			b_writ++;
		}
		fmt++;
	}
	va_end(args);
	return (b_writ);
}

/* Comparison printf/ft_print outputs. Kept for debugging and expanding. */
/*
int	main(void)
{
	int	whatever = 5;
	printf("Pt: %p \n", &whatever);
	int	*void_p = NULL;
	//	int	*whatever_p = &whatever;
	printf("[PRINTF]%d [FT_PRINTF]%d \n", 
		printf("%c\n", 'x'), ft_printf("%c\n", 'x'));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", 
		printf("%s\n", "One string"), ft_printf("%s\n", "One string"));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", 
		printf("%s - %s\n", "String 1", "String 2"), 
		ft_printf("%s - %s\n", "String 1", "String 2"));

	printf("[PRINTF]%d [FT_PRINTF]%d \n", 
		printf("%d\n", 1), ft_printf("%d\n", 1));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", 
		printf("%d\n", -12), ft_printf("%d\n", -12));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", 
		printf("%d - %d\n", -1234567, 777), 
		ft_printf("%d - %d\n", -1234567, 777));
	
	printf("[PRINTF]%d [FT_PRINTF]%d \n", 
		printf("%u\n", -1), ft_printf("%u\n", -1));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", 
		printf("%u\n", -12), ft_printf("%u\n", -12));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", 
		printf("%u\n%u\n", -1234567, 777), 
		ft_printf("%u\n%u\n", -1234567, 777));

	printf("[PRINTF]%d [FT_PRINTF]%d \n", 
		printf("pr %p\n", void_p), ft_printf("ft %p\n", void_p));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", 
		printf("pr %#x\n", 36453), ft_printf("ft %#x\n", 36453));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", 
		printf("pr %#x\n", 777), ft_printf("ft %#x\n", 777));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", 
		printf("pr %#x\n", 15), ft_printf("ft %#x\n", 15));
	printf("[PRINTF]%d [FT_PRINTF]%d \n", 
		printf("pr %#x\n", 0), ft_printf("ft %#x\n", 0));
}
*/

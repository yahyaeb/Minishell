/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 09:58:07 by mmalie            #+#    #+#             */
/*   Updated: 2024/11/14 09:28:52 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
/* 
 * Converts an integer to a dynamically allocated string representation.
 */
char		*ft_itoa(int n);
static int	get_sign(int n);
static int	get_nb_digits(int uns_n);
static void	copy_nb_to_str(char *dest, int uns_nb, int nb_digits, int sign);
static char	*handle_special_cases(char *array, int n);

char	*ft_itoa(int n)
{
	char	*result_str;
	int		sign;
	int		uns_n;
	int		nb_digits;

	result_str = NULL;
	if (n == 0 || n == -0 || n == -2147483648)
	{
		result_str = handle_special_cases(result_str, n);
		if (result_str == NULL)
			return (NULL);
		return (result_str);
	}
	sign = get_sign(n);
	uns_n = n * sign;
	nb_digits = get_nb_digits(uns_n);
	if (n < 0)
		nb_digits++;
	result_str = (char *)malloc(sizeof(char) * (nb_digits + 1));
	if (result_str == NULL)
		return (NULL);
	copy_nb_to_str(result_str, uns_n, nb_digits, sign);
	return (result_str);
}

static char	*handle_special_cases(char *array, int n)
{
	char	*int_min;

	int_min = "-2147483648";
	if (n == 0 || n == -0)
	{
		array = (char *)malloc(sizeof(char) * (1 + 1));
		if (array == NULL)
			return (NULL);
		array[0] = '0';
		array[1] = '\0';
	}
	else if (n == -2147483648)
	{
		array = (char *)malloc(sizeof(char) * (11 + 1));
		if (array == NULL)
			return (NULL);
		ft_strlcpy(array, int_min, 12);
		array[11] = '\0';
	}
	return (array);
}

static int	get_sign(int n)
{
	if (n < 0)
		return (-1);
	else
		return (1);
}

static int	get_nb_digits(int uns_n)
{
	int	nb_digits;

	nb_digits = 1;
	while (uns_n > 9)
	{
		uns_n = uns_n / 10;
		nb_digits++;
	}
	return (nb_digits);
}

static void	copy_nb_to_str(char *dest, int uns_nb, int nb_digits, int sign)
{
	int	i;

	i = nb_digits;
	while (uns_nb > 9)
	{
		i--;
		dest[i] = (uns_nb % 10) + '0';
		uns_nb = uns_nb / 10;
	}
	dest[i - 1] = uns_nb + '0';
	if (sign < 0)
		dest[0] = '-';
	dest[nb_digits] = '\0';
}

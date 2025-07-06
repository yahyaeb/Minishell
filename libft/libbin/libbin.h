/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libbin.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:25:28 by mmalie            #+#    #+#             */
/*   Updated: 2024/12/20 21:45:07 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBBIN_H
# define LIBBIN_H

/* LIBBIN - For bit manipulation */
void			ft_show_bin(int num, unsigned int nb_of_bytes);
void			ft_get_bin(int num, char binary[33]);
char			ft_bin_to_char(char binary[9]);
	// Basic bit operations
unsigned int	ft_set_bit(unsigned int num, int bit_pos);
unsigned int	ft_clear_bit(unsigned int num, int bit_pos);
unsigned int	ft_toggle_bit(unsigned int num, int bit_pos);
int				ft_is_bit_set(unsigned int num, int bit_pos);
	// Counting bits
int				ft_count_set_bits(unsigned int num);
int				ft_count_clear_bits(unsigned int num);
int				ft_first_set_bit_pos(unsigned int num);
int				ft_highest_set_bit_pos(unsigned int num);

	// Masking bits
unsigned int	ft_extract_bits(unsigned int n, int st, int en);
unsigned int	ft_set_bits(unsigned int n, int st, int en, unsigned int val);
int				ft_match_bits(unsigned int n, int st, int en, unsigned int val);
	// Shifting and rotating
unsigned int	ft_rotate_left(unsigned int num, int shift_amount);
unsigned int	ft_rotate_right(unsigned int num, int shift_amount);
int				ft_arithmetic_shift_left(int num, int shift_amount);
int				ft_arithmetic_shift_right(int num, int shift_amount);
	// Testing and comparison
int				ft_is_power_of_two(unsigned int num);
int				ft_are_bits_equal(unsigned int num1, unsigned int num2);
	// Utilities
unsigned int	ft_reverse_bits(unsigned int num);
unsigned int	ft_swap_bits(unsigned int num, int bit1_pos, int bit2_pos);
int				ft_count_leading_zeros(unsigned int num);
int				ft_count_trailing_zeros(unsigned int num);
int				ft_get_parity(unsigned int num);
	// Specialized operations
unsigned int	ft_pack_two_int(unsigned int int1, unsigned int int2); // To do
unsigned int	ft_unpack_first_half(unsigned int packed); // To do
unsigned int	ft_unpack_second_half(unsigned int packed); // To do
	// Custom bit patterns
unsigned int	ft_create_bitmask(int num_bits);
unsigned int	ft_create_range_bitmask(int start_bit, int end_bit);

#endif

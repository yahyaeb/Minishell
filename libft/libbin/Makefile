# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2025/02/15 11:11:04 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### Name of the file obtained after compilation ###
###################################################

NAME = libbin.a

############################
### Compilation settings ###
############################

CC=cc
CFLAGS=-Wall -Wextra -Werror

AR=ar
ARFLAGS=-rcs

####################
### Dependencies ###
####################

DEPS_LIBFT = ../libft.h
DEPS = libbin.h

####################
### Source files ###
####################

LIBBIN = ft_show_bin.c \
	 ft_bin_to_char.c \
	 ft_set_bit.c \
	 ft_clear_bit.c \
	 ft_toggle_bit.c \
	 ft_is_bit_set.c \
	 ft_count_set_bits.c \
	 ft_count_clear_bits.c \
	 ft_first_set_bit_pos.c \
	 ft_highest_set_bit_pos.c \
	 ft_extract_bits.c \
	 ft_set_bits.c \
	 ft_match_bits.c \
	 ft_rotate_left.c \
	 ft_rotate_right.c \
	 ft_arithmetic_shift_left.c \
	 ft_arithmetic_shift_right.c \
	 ft_is_power_of_two.c \
	 ft_are_bits_equal.c \
	 ft_reverse_bits.c \
	 ft_swap_bits.c \
	 ft_count_leading_zeros.c \
	 ft_count_trailing_zeros.c \
	 ft_get_parity.c \
	 ft_pack_two_int.c \
	 ft_unpack_first_half.c \
	 ft_unpack_second_half.c \
	 ft_create_bitmask.c \
	 ft_create_range_bitmask.c \

SRC = ${LIBBIN}

####################
### Object files ###
####################

OBJ_DIR = ./obj

OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o, $(SRC))

### Default rules (compile the executable)
all: $(NAME)
	@echo
	@echo "===================================================================================="
	@echo "                         0️⃣  1️⃣  🧠 Compiling LIBBIN...                               "
	@echo "===================================================================================="
	@echo "                      L       III  BBBBB  BBBBB   III  N   N                        "
	@echo "                      L        I   B   B  B   B    I   NN  N                        "
	@echo "                      L        I   BBBB   BBBB     I   N N N                        "
	@echo "                      L        I   B   B  B   B    I   N  NN                        "
	@echo "                      LLLLL   III  BBBBB  BBBBB   III  N   N                        "
	@echo "===================================================================================="
	@echo "                          L I B B I N   C O M P I L E D! 💡 ✅                      "
	@echo "                         Bits toggled, shifting complete! 🔄                        "
	@echo "===================================================================================="

###############################
### Create a static library ###
###############################

$(NAME): | $(OBJ_DIR) $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

### Compile .c files into .o files and store in ./obj
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@ 

### Create ./obj folder if missing
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

#########################
### Cleaning-up rules ###
#########################

clean:
	rm -f $(OBJ)
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

# Rule to recompile everything (execute fclean, then re)
re: fclean all

#########################
### .PHONY Exceptions ###
#########################

.PHONY: all clean fclean re bonus

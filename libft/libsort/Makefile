# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2025/02/15 11:09:19 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### Name of the file obtained after compilation ###
###################################################

NAME = libsort.a

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
DEPS = ./libsort.h

####################
### Source files ###
####################

LIBSORT_UTILS = ft_swap_ints.c \
		ft_shift_right_ints.c \
		ft_rev_arr_int.c \
		ft_cpy_arr_int.c \

LIBSORT = ft_bub_srt.c \
	    ft_sel_srt.c \
	    ft_ins_srt.c \
	    ft_mrg_srt.c \
	    #ft_qck_srt.c \
	    #ft_hep_srt.c \
	    #ft_rdx_srt.c \

SRC = ${LIBSORT_UTILS} ${LIBSORT}

####################
### Object files ###
####################

OBJ_DIR = ./obj

OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o, $(SRC))

### Default rules (compile the executable)
all: $(NAME)
	@echo
	@echo "====================================================================================" 
	@echo "                         🔽 🔼 📊 Compiling LIBSORT...                              "
	@echo "===================================================================================="	
	@echo "                   L       III  BBBBB  SSSSS  OOOOO  RRRR   TTTTT                   "
	@echo "                   L        I   B   B  S      O   O  R   R    T                     "
	@echo "                   L        I   BBBB   SSSSS  O   O  RRRR     T                     "
	@echo "                   L        I   B   B      S  O   O  R  R     T                     "
	@echo "                   LLLLL   III  BBBBB  SSSSS  OOOOO  R   R    T                     "
	@echo "===================================================================================="
	@echo "                        L I B S O R T   C O M P I L E D! 🪆 ✅                      "
	@echo "                            Sorting complete! 🎯                                    "	
	@echo "===================================================================================="
	@echo	

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

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2025/05/20 12:24:05 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### Name of the file obtained after compilation ###
###################################################

NAME = libstdlib.a

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
DEPS = libstdlib.h

####################
### Source files ###
####################

LIBSTDLIB = ft_atoi.c \
	    ft_atol.c\
	    ft_atoll.c \
	    ft_calloc.c \
	    ft_memdel.c \
	    ft_free_two_str.c \

SRC = ${LIBSTDLIB}

####################
### Object files ###
####################

OBJ_DIR = ./obj

OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o, $(SRC))

### Default rules (compile the executable)
all: $(NAME)
	@echo
	@echo "===================================================================================="
	@echo "                       🔢 💾 🗑️  Compiling LIBSTDLIB...                             "
	@echo "===================================================================================="
	@echo "            L      III  BBBBB  SSSSS  TTTTT  DDDD   L      III  BBBBB               "
	@echo "            L       I   B   B  S        T    D   D  L       I   B   B               "
	@echo "            L       I   BBBB   SSSSS    T    D   D  L       I   BBBB                "
	@echo "            L       I   B   B      S    T    D   D  L       I   B   B               "
	@echo "            LLLLL  III  BBBBB  SSSSS    T    DDDD   LLLLL  III  BBBBB               "
	@echo "===================================================================================="
	@echo "                   L I B S T D L I B   C O M P I L E D! ♻️  ✅                     "
	@echo "                          Standard functions ready! ⚙️                               "
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

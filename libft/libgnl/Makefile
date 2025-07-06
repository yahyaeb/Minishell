# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2025/02/15 10:48:02 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### Name of the file obtained after compilation ###
###################################################

NAME = libgnl.a

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
DEPS = libgnl.h

####################
### Source files ###
####################

LIBGNL = ft_gnl.c \
	 ft_gnl_utils.c \

SRC = ${LIBGNL}

####################
### Object files ###
####################

OBJ_DIR = ./obj

OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o, $(SRC))

### Default rules (compile the executable)
all: $(NAME)
	@echo
	@echo "====================================================================================" 
	@echo "                         📖 📝 💾 Compiling LIBGNL...                               "
	@echo "===================================================================================="
	@echo "                      L       III  BBBBB   GGGG  N   N  L                           "
	@echo "                      L        I   B   B  G      NN  N  L                           "
	@echo "                      L        I   BBBB   G  GG  N N N  L                           "
	@echo "                      L        I   B   B  G   G  N  NN  L                           "
	@echo "                      LLLLL   III  BBBBB   GGG   N   N  LLLLL                       "
	@echo "===================================================================================="
	@echo "                        L I B G N L   C O M P I L E D! 📚 ✅                        "
	@echo "                          Ready to read lines efficiently! 📑                       "
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

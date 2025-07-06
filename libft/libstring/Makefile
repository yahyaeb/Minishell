# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmalie <mmalie@student.42nice.fr           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/14 09:35:38 by mmalie            #+#    #+#              #
#    Updated: 2025/04/11 21:37:06 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### Name of the file obtained after compilation ###
###################################################

NAME = libstring.a

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
DEPS = libstring.h

####################
### Source files ###
####################

LIBSTRING = ft_bzero.c \
	    ft_memchr.c \
	    ft_memcmp.c \
	    ft_memcpy.c \
	    ft_memmove.c \
	    ft_memset.c \
	    ft_strchr.c \
	    ft_strdel.c \
	    ft_strdup.c \
	    ft_strlcat.c \
	    ft_strlcpy.c \
	    ft_strlen.c \
	    ft_strcmp.c \
	    ft_strncmp.c \
	    ft_strnew.c \
	    ft_strnopbrk.c \
	    ft_strnstr.c \
	    ft_strpbrk.c \
	    ft_strrchr.c \
	    ft_strrev.c \

SRC = ${LIBSTRING}

####################
### Object files ###
####################

OBJ_DIR = ./obj

OBJ = $(patsubst %.c,$(OBJ_DIR)/%.o, $(SRC))

### Default rules (compile the executable)
all: $(NAME)
	@echo
	@echo "===================================================================================="
	@echo "                       🔤 📜 ⚙️  Compiling LIBSTRING..."
	@echo "===================================================================================="
	@echo "             L      III  BBBBB  SSSSS  TTTTT  RRRR   III  N   N  GGGGG              "
	@echo "             L       I   B   B  S        T    R   R   I   NN  N  G                  "
	@echo "             L       I   BBBB   SSSSS    T    RRRR    I   N N N  G  GG              "
	@echo "             L       I   B   B      S    T    R  R    I   N  NN  G   G              "
	@echo "             LLLLL  III  BBBBB  SSSSS    T    R   R  III  N   N   GGGG              "
	@echo "===================================================================================="
	@echo "                      L I B S T R I N G   C O M P I L E D! 🧵 ✅                  "
	@echo "                         String functions ready!  ✍️                                "
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

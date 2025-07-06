# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 07:44:20 by yel-bouk          #+#    #+#              #
#    Updated: 2025/06/14 22:18:54 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
CC = gcc
CFLAGS = -g -fsanitize=address -Werror -Wextra -Wall
LIBFT_DIR = ft_libft
LIBFT = ./ft_libft/ft_libft.a
SRCS = pipex.c \
		free.c \
		parsing.c \
		pipex_bonus.c \
		pipex_utils.c \
		pipex_bonus_utils.c \
                err_cases.c \

OBJS = $(SRCS:.c=.o)

all: libft $(NAME)

libft:
	$(MAKE) -C $(LIBFT_DIR)

# Compile Executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

# Rule for Compiling .c Files into .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean .o Files
clean:
	rm -f $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

# Clean Everything
fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

# Rebuild Everything
re: fclean all

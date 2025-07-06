# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/20 17:50:19 by mmalie            #+#    #+#              #
#    Updated: 2025/06/17 19:48:57 by mmalie           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

###################################################
### Name of the file obtained after compilation ###
###################################################

NAME = minishell

############################
### Compilation settings ###
############################

CC=cc
CFLAGS=-g -Wall -Wextra -Werror

####################
### Dependencies ###
####################

DEPS = ./inc/minishell.h ./inc/defines.h ./inc/global_var.h ./libft/libft.h
LIBFT = ./libft/libft.a

####################
### Source files ###
####################

MS_SRC = ./src/minishell.c \
      ./src/shell_core/ms_initer.c \
      ./src/shell_core/ms_normalizer.c \
      ./src/shell_core/ms_normalizer_add_spaces.c \
	  ./src/shell_core/ms_normalize_add_spaces_utils.c \
      ./src/shell_core/ms_flagger.c \
      ./src/shell_core/ms_commands_manager.c \
      ./src/shell_core/ms_input_manager.c \
      ./src/shell_core/ms_quotes_handler.c \
      ./src/shell_core/ms_env_interpreter.c \
      ./src/shell_core/ms_nametoval.c \
      ./src/shell_core/ms_nametoval_cases.c \
      ./src/shell_core/ms_free.c \
      ./src/shell_core/yahya_ms_to_pipex.c \
      ./src/builtins/cd/ms_cmd_cd.c \
      ./src/builtins/cd/ms_cmd_cd_chdir.c \
      ./src/builtins/cd/ms_cmd_cd_dotdot.c \
      ./src/builtins/cd/ms_cmd_cd_utils.c \
      ./src/builtins/cd/ms_cmd_cd_logical_path.c \
      ./src/builtins/cd/ms_cmd_cd_merger.c \
      ./src/builtins/echo/ms_cmd_echo.c \
      ./src/builtins/env/ms_cmd_env.c \
      ./src/builtins/exit/ms_cmd_exit.c \
      ./src/builtins/export/ms_cmd_export.c \
      ./src/builtins/pwd/ms_cmd_pwd.c \
      ./src/builtins/unset/ms_cmd_unset.c \
      ./src/utils/ms_env_utils.c \
      ./src/utils/ms_stash_utils.c \
      ./src/utils/ms_cd_path_utils.c \
      ./src/utils/ms_split_join_utils.c \
      ./src/utils/ms_strs_utils.c \
      ./src/utils/ms_replace_utils.c \
      ./src/utils/ms_flags_utils.c \
      ./src/utils/ms_debug_utils.c \
      ./src/utils/ms_args_utils.c \
      ./src/utils/ms_parsing_utils.c \
      ./src/utils/ms_handle_basic_pipe_utils.c \
      ./src/yahya_parsing.c \
      ./src/parsing_utils_ye.c \
      ./src/shell_core/ms_pipex_utils.c \
      ./src/shell_core/ms_input_manager_converter.c \
	  ./src/shell_core/ms_hand_red.c \
	  ./src/shell_core/cmd_classifier.c \
	  ./src/shell_core/ms_handle_basic_pipe.c \
	  ./src/shell_core/ms_handle_pipe_with_red.c \
	  ./src/shell_core/exec_with_redir_sign.c \
        ./src/shell_core/ms_handle_pipe_w_red_utils.c \
		./src/shell_core/ms_handle_pipe_w_red_loop.c \
        ./src/shell_core/ms_handle_pipes_utils.c \
        ./src/shell_core/exec_with_redir.c \
        ./src/shell_core/exec_with_redir_utils.c \
	./src/shell_core/exec_with_redir_exit_cases.c \
        ./src/shell_core/cmd_classifier_utils.c \
        ./src/shell_core/ms_to_pipex_utils.c \
		./src/shell_core/ms_env_interpreter_spaces.c \
        ./src/shell_core/ms_hand_red_utils.c \
        ./src/shell_core/ms_hand_red_exec.c \
        ./src/ms_exec_handler.c \
        ./src/ms_minishell_utils.c \
        ./src/ms_exec_hanlder_utils.c \
	./src/loop_and_basic_cases.c \
        ./src/shell_core/ms_pipex_count_cmds.c \
        ./src/shell_core/check_consec_redir.c \


PIPEX_SRC =       ./pipex_ms/pipex.c \
      ./pipex_ms/pipex_utils.c \
      ./pipex_ms/pipex_bonus.c \
      ./pipex_ms/pipex_bonus_utils.c \
      ./pipex_ms/parsing.c \
      ./pipex_ms/free.c \
      ./pipex_ms/pipex_here_doc.c \

SRC = $(MS_SRC) $(PIPEX_SRC)

PIPEX_SRC =       ./pipex_ms/pipex.c \
      ./pipex_ms/pipex_utils.c \
      ./pipex_ms/pipex_bonus.c \
      ./pipex_ms/pipex_bonus_utils.c \
      ./pipex_ms/parsing.c \
      ./pipex_ms/free.c \
      ./pipex_ms/pipex_here_doc.c \
      ./pipex_ms/pipex_here_doc_env.c \
      ./pipex_ms/pipex_here_doc_utils.c \

SRC = $(MS_SRC) $(PIPEX_SRC)

### Object files
OBJ = $(SRC:.c=.o)

##############################################
### Default rules (compile the executable) ###
##############################################

all: $(LIBFT) $(NAME)

$(LIBFT):
	cd libft && make

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(OBJ) -Llibft -lft -lreadline -lncurses -o $(NAME)

######################################
### Compile .c files into .o files ###
######################################

$(OBJ): %.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

#########################
### Cleaning-up rules ###
#########################

clean:
	cd libft && make clean
	rm -f $(OBJ)

fclean: clean
	cd libft && make fclean
	rm -f $(NAME)

re: fclean all

#########################
### .PHONY Exceptions ###
#########################

.PHONY: all clean fclean re bonus

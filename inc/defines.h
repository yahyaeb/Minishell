/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:05:05 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/16 11:03:46 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define DEBUG 0

# define NB_CMDS 7

# define STDOUT 1
# define STDERR 2

# define PROMPT_STYLE "ms> "

/* Control chars */
# define CC_REDIR_IN  24  // "<"
# define CC_REDIR_OUT 25 // ">"
# define CC_APPEND    26  // ">>"
# define CC_HEREDOC   27 // "<<"
# define CC_PIPE 28 // "|"

# define CC_SPACE_IN_QUOTE 29
# define CC_VAR_TO_INTERPRET 30
# define CC_SUBARG_DELIM 31
# define CC_LONE_DOLLAR 23
# define CC_EXTRA_DELIM 31
# define CC_VAR_BOUND 21
# define CC_VAR_BOUND_SQUOTE 19
# define CC_TO_BE_DELETED 20
# define CC_TRAILING_DOLLAR 19
# define CC_DOLLAR_UNCLOSED 18
# define CC_EMPTY_STR 17

/* Return messages (ft_ret) */
# define SHELL_NAME "minishell: "

# define TOO_MANY_ARGS ": too many arguments\n"
# define HOME_NON_SET ": HOME non set\n"
# define NO_FILE_OR_DIR ": No such file or directory\n"
# define INVALID_ID "': not a valid identifier\n"
# define NUM_ARG_REQ ": numeric argument required\n"
# define CMD_NOT_FOUND ": command not found\n"
# define CMD_IS_DIR ": Is a directory\n"
# define PERM_DENY ": Permission denied\n"
# define SYNTAX_ERR "syntax error near unexpected token\n"
# define NO_CUR_DIR ": error retrieving current directory"
# define NO_ACC_PAR ": getcwd: cannot access parent directories\n"
# define PWD_NON_SET ": PWD non set\n"
# define OLDPWD_NON_SET ": OLDPWD non set\n"

#endif

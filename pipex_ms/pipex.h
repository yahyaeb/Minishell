/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 18:54:10 by yel-bouk          #+#    #+#             */
/*   Updated: 2025/06/17 17:27:33 by yel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pipex.h
#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include <stdio.h>
# include <string.h>
# include "../libft/libft.h"
# include <readline/readline.h>

typedef enum e_bool
{
	false,
	true
}	t_bool;

typedef struct s_pipex
{
	int			in_fd;
	int			out_fd;
	t_bool		here_doc;
	char		**cmd_paths;
	char		***cmd_args;
	int			cmd_count;
	char		**envp;
	int			exit_status;
}	t_pipex;

typedef struct s_commands
{
	char	**argv;
	char	*infile;
	char	*outfile;
	char	*limiter;
	t_bool	append;
}	t_commands;

typedef struct s_pipeline
{
	char		**tokens;
	t_commands	*cmds;
	int			cmd_count;
	t_pipex		*pipex;
}	t_pipeline;

void	ft_exit_error(t_pipex *pipex, const char *msg);
void	ft_free_array(char **arr, int count);
void	ft_free_2d_array(char **arr);
void	free_pipex(t_pipex *pipex);
void	ft_init_pipex(t_pipex *pipex, char *infile, char *outfile);
void	ft_parse_cmds(t_pipex *pipex, char **argv);
void	ft_parse_paths(t_pipex *pipex);
char	*find_cmd_path(char *cmd, char **paths);
char	*get_path_from_env(char *envp[]);
void	ft_execute_pipex(t_pipex *pipex);
void	execute_first_child(t_pipex *pipex, int *pipefd);
void	execute_second_child(t_pipex *pipex, int *pipefd);
void	handle_mandatory(t_pipex *pipex, char **argv, int argc);
void	handle_bonus(t_pipex *pipex, int argc, char **argv, int len);
void	execute_multiple_cmds(t_pipex *pipex);
void	execute_child(t_pipex *pipex, int in_fd, int out_fd, char **cmd);
void	handle_here_doc(t_pipex *pipex, int argc, char **argv);
void	ft_parse_here_doc(t_pipex *pipex, char **argv);
void	wait_for_all_children(t_pipex *pipex, int count);
void	execute_all_children(t_pipex *pipex);
void	execute_here_doc(t_pipex *pipex);
void	execute_last_child(t_pipex *pipex, int *pipefd);
void	execute_first_child(t_pipex *pipex, int *pipefd);
void	execute_second_child(t_pipex *pipex, int *pipefd);
void	execute_child(t_pipex *pipex, int in_fd, int out_fd, char **cmd);
void	ft_exit_error(t_pipex *pipex, const char *msg);
void	check_here_doc_args(t_pipex *pipex, int argc);
void	read_heredoc_input(t_pipex *pipex, char *limiter);
void	setup_here_doc_fds(t_pipex *pipex, char *outfile);
void	parse_here_doc_commands(t_pipex *pipex, int argc, char **argv);
void	fork_and_run(t_pipex *pipex, int i, int prev_fd, int *pipefd);
int		run_pipex_from_minshell(t_pipeline *pipeline,
			char **envp, int exit_status);
char	*join_args(char **args);
void	ft_init_pipex(t_pipex *pipex, char *infile, char *outfile);
int		handle_heredoc(const char *limiter, int exit_status);
int		run_pipex_from_minshell(t_pipeline *pipeline,
			char **envp, int exit_status);
int		allocate_mem(char **str, int length);
size_t	total_args_length(char **args);
char	*join_args(char **args);
void	init_pipex(t_pipex *pipex, char **envp);
int		handle_heredoc_error(t_pipeline *pipeline);
int		handle_pipex_in_fd_error(t_pipex pipex);
int		pipex_error_heredoc(char *msg, int value);
void	setup_outfd(t_pipex *pipex, char **argv, int argc);
char	*expand_env_vars(const char *line, int exit_status);
int		open_heredoc_file(void);
void	free_line_and_close_fd(char *line, int fd);
int		heredoc_loop(char *line, const char *limiter, int fd, int exit_status);
char	*strip_quotes_and_encode_expand(char *str);
int		open_heredoc_file(void);
#endif

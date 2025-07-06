/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-bouk <yel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 22:05:05 by mmalie            #+#    #+#             */
/*   Updated: 2025/06/17 19:33:02 by mmalie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "defines.h"

/* Libraries */

	// Pipex
# include "../pipex_ms/pipex.h"

	// Standard libraries
# include <curses.h>
# include <dirent.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/time.h>
# include <sys/resource.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <term.h>
# include <unistd.h>

	// Libft
# include "../libft/libft.h"

	// Global var
# include "global_var.h"

/* Structures */

struct	s_shell;

typedef struct s_parse_redir_ctx
{
	t_pipeline	*p;
	t_commands	*cmd;
	char		**argv;
	int			arg_i;
	int			i;
}			t_parse_redir_ctx;

typedef struct s_cmd_flags
{
	int	has_pipe;
	int	has_redir;
	int	here_doc;
	int	has_cmd;
	int	first_is_redir;
	int	consecutive_redirs;
}			t_cmd_flags;

typedef struct s_command
{
	char	*name;
	int		(*func)(struct s_shell *);
	char	*doc;
}			t_command;

typedef struct s_shell
{
	HISTORY_STATE	hist;
	t_command		**cmds;
	t_pipeline		*pipeline;
	t_list			*this_env;
	t_list			*env_stash;
	char			*normalized_line;
	char			**input_args;
	int				last_exit_status;
	char			**tokens;
	int				logical_up_count;
	char			*last_logical_pwd;
}				t_shell;

typedef struct s_normalize_var
{
	int		len;
	int		op_len;
	int		i;
	int		j;
	int		k;
	int		count;
}			t_normalize_var;

typedef struct s_parse_state
{
	char	*last_outfile;
	bool	last_append;
	int		test_fd;
}			t_parse_state;

typedef struct s_parse_context
{
	t_commands		*cmd;
	t_parse_state	*fd;
	char			**tokens;
	int				i;
	int				argc;
}			t_parse_context;

typedef struct s_parse_utils
{
	int		num_cmds;
	int		i;
	int		cmd_index;
	int		start;
	char	pipe_token[2];
}			t_parse_utils;

typedef struct s_exec_context
{
	t_pipeline	*pipeline;
	int			cmd_index;
	int			prev_fd;
	int			pipe_fd[2];
	t_shell		*sh;
	char		**env;
	int			in_fd;
	int			out_fd;
	int			redir_status;
}			t_exec_context;

typedef struct s_pipeline_loop_context
{
	t_pipeline	*pipeline;
	int			cmd_index;
	int			prev_fd;
	int			pipe_fd[2];
	t_shell		*sh;
	char		**env;
	int			in_fd;
	int			out_fd;
	int			redir_status;
}			t_pipeline_loop_context;

typedef struct s_pipeline_parser
{
	t_pipeline		*pipeline;
	char			**tokens;
	t_parse_utils	*build;
}			t_pipeline_parser;

/* Prototypes */

// ./SHELL_CORE

	// minishell.c
int			main(int argc, char **argv, char **env);
int			is_invalid_for_stash(char *arg);

	// ms_initer.c
int			init_shell(t_shell *sh, char **env);
int			init_env(t_shell *sh, char **env);
int			normalize_env(t_list *this_env);
void		init_signals(t_shell *sh);
void		signal_handler(int signum);

	// ms_input_manager.c
char		*get_input(char *line);
char		**normalize_input(char *line, t_shell *sh);
int			process_input(t_shell *sh);
int			handle_non_cmd(t_shell *sh, int res);
int			handle_file_or_dir(t_shell *sh);

	// ms_normalizer.c
char		*ft_normalize(char *line);
char		*ft_strflag(char *line);
char		*copy_collapse(char *dst, char *src, size_t src_len);
void		flag_double_quotes(char *src);
char		*replace_cc_empty_str(t_shell *sh);

	// ms_normalizer_add_spaces.c
char		*ft_add_spaces_around_redir(char *spaced);
char		*ft_add_spaces_around(char *str, char special);
char		*ft_add_spaces_around_str(const char *line, const char *str);

	// ms_flagger.c
void		flag_dollar(char *line, int *i);
void		flag_pipe_and_redir(char *line, int *i);
void		flag_quote(char *line, int *i);

	// ms_quotes_handler.c
void		flag_var_bounds(char *line, int *i);
void		handle_quote(char *line, char quote_type, int *i);
void		ante_merge_quote(char *line, int *i);
void		pass_quotes(char *dst, char *src, size_t *i, size_t *j);
int			two_quotes_case(char *dst, char *src, size_t *i, size_t *j);

	// ms_env_interpreter.c
int			ft_interpret_env(t_shell *sh);
char		*rejoin_arg(t_shell *sh, char *rejoined_arg,
				char **split_args, int i);
char		**ft_copy_free(char **input_arg, char *rejoined_arg);
void		remove_empty_args(char **args);

	// ms_nametoval.c
char		*ft_nametoval(t_shell *sh, char *rejoined_arg, char **split_args);
char		*rejoin_subarg(char **subargs, char *delim);
char		*split_rejoin(t_shell *sh, char *rejoined_arg,
				char *arg, char splitter);
char		*to_delim(t_shell *sh, char **subargs, char symbol);

	// ms_nametoval_cases.c
char		*handle_special_cases(t_shell *sh, char *joined,
				char *split, char *end);
char		*handle_exit_status_case(t_shell *sh, char *rejoined_arg,
				char *subarg);
char		*handle_var_case(t_shell *sh, char *rejoined_arg, char *arg);

	// ms_commands_manager.c
int			init_cmds(t_shell *sh);
t_command	*register_cmd(char *name, void *func, char *doc);
t_command	*is_registered_cmd(t_shell *sh);

	// ms_free.c
void		free_memory(t_shell *sh);
void		free_args(char **input_args);
void		free_list(t_list **list);
void		free_commands(t_command **cmds);
char		*free_incomplete_strs(char **arr, int up_to);

// ./BUILTINS

	// ms_cmd_cd.c - Change the working directory
int			cmd_cd(t_shell *sh);
int			cd_process_path(t_shell *sh, char *cwd, char *path,
				char *user_path);
int			cd_set_path(t_shell *sh, t_list *home_var,
				char **path);
char		*fallback_to_pwd_if_cwd_fails(t_shell *sh);
int			handle_cd_path_failure(char *user_path, char *cwd);

	// ms_cmd_cd_chdir.c
int			change_directory(t_shell *sh, char *cwd, char *path,
				char *user_path);
int			cd_case_invalid_chdir(t_shell *sh, char *cwd,
				char *user_path, char *logical_pwd);
int			cd_case_invalid_cwd(t_shell *sh, char *cwd,
				char *user_path, char *logical_pwd);
void		update_pwds_vars(t_shell *sh, char *prev_cwd, char *new_pwd);
void		update_pwd_var(t_shell *sh, char **split_pwd, char *key);

	// ms_cmd_cd_dotdot.c
char		*handle_cd_dotdot_case(char *pwd,
				char **pwd_split, char **path_split);
int			test_pwd_split(char **pwd_split, char *current_path,
				int i, int *deleted_dirs);
void		reset_count_and_free(int *cd_up_count, int *deleted_dirs,
				char **pwd_split, char **path_split);

	// ms_cmd_cd_logical_path.c
char		*apply_logical_cd(char *pwd, char *cd_path);
char		*resolve_logical_path(char *cwd, char *user_path);
int			try_logical_cd(t_shell *sh, char *cwd, char *user_path);
int			simulate_path(t_shell *sh, char *cwd, char *logical_path);
int			handle_relative_cd(t_shell *sh, char *cwd,
				char *path, char *user_path);

	// ms_cmd_cd_utils.c
char		*join_parts(char **parts, int i);
int			append_and_replace(char **dst, char *suffix);
void		update_if_exists(char **last_existing, char *current);
char		*find_last_existing_dir(char *path, int i);

	// ms_cmd_cd_merger
char		*merge_pwd_and_path(char **pwd_split, char **path_split,
				int i, int j);
void		init_to_null(char **result);
int			try_merge(char **path_split, char **result, int i, int j);

	// ms_cmd_echo.c - Display a line of text
int			cmd_echo(t_shell *sh);
void		echo_set_n(char **input_args, bool *opt_n, int *i);
char		*echo_process_all_args(t_shell *sh, char *joined_input, int *i);
char		*echo_join_input(char *joined_input, char **input_args, int *i);
void		echo_display(char *joined_output, bool opt_n);

	// ms_cmd_env.c - Display the env variables
int			cmd_env(t_shell *sh);

	// ms_cmd_exit.c - Cause the shell to exit
int			cmd_exit(t_shell *sh, unsigned int status);
void		free_and_exit(t_shell *sh, unsigned int status);
int			ft_isnum(char *str);
char		*ms_trim(char *trimmed_arg, char *arg, int len, int k);
int			exit_arg_overflow(char *str);

	// ms_cmd_export.c - Set the export attribute for variables
void		sort_env_array(char **env_array, int count);
void		print_sorted_export(char **env_array);
int			cmd_export(t_shell *sh);
int			try_export(t_shell *sh, size_t *i);
int			export_from_term(t_shell *sh, size_t *i);
void		export_from_stash(t_shell *sh, t_list *stashed_var);

	// ms_cmd_pwd.c - Print name of current/working directory
int			cmd_pwd(t_shell *sh);
char		*store_cwd(char *cwd);

	// ms_cmd_unset.c - Unset values and attributes of variables and functions
int			cmd_unset(t_shell *sh);
t_list		*get_prev_node(t_list *cur_node, t_list *this_env);

	// ./UTILS

	// ms_cd_path_utils.c
char		*handle_dotted_path(char *cwd, char *path);
char		*get_abs_path(char *joined_path, char *cwd, char *path);
char		**split_abs_path(char **split_path, char *joined_path);
void		flag_dotted_path(char **split_path, char ctrl_char);
char		*rejoin_abs_path(char *rejoined_path, char **split_path,
				int i, int j);

	// ms_debug_utils.c
void		ft_show_strs(char **strs, char *debug_msg);
int			ft_ret(int return_val, char *msg, int fd);
int			ms_err(char *cmd_name, char *arg, char *err_msg, int return_val);

	// ms_env_utils.c
t_list		*ft_getenv(char *var_name, t_list **this_env);
char		*ft_setenv(t_list *set_var, char *arg);
int			is_valid_env_name(char *var_name);
int			add_new_env_var(t_shell *sh, char **split_str);
int			ft_update_env_value(t_list *set_var, char **split_str);

	// ms_flags_utils.c
void		ft_flag_delim(char *str, char delim, char flag, char *mode);
void		ft_flag_all_but_first(char *str, char delim, char flag);
void		ft_unflag_delim(char *str, char delim, char flag);
char		**split_input_arg(t_shell *sh, size_t *i);

	// ms_replace_utils.c
void		ft_replace_if_space(char *cur_c, char new_c);
void		ft_replace_char(char *cur_c, char new_c);
void		ft_replace_chars_in_str(char *str, char cur_c, char new_c);
void		ft_replace_all_chars(char **input_args, char old_c, char new_c);

	// ms_split_join_utils.c
char		*ft_chrtostr(char chr);
char		*join_with_delim(char *result, char *temp, char delim);
char		*join_all_subargs(char **args, char delim);
char		*ft_strjoin_delim(char const *s1, char const *s2,
				char const *delim);
char		*ft_rejoin_subarg(char *rejoined_arg, char *arg);

	// ms_stash_utils.c
int			stash_var(t_shell *sh);
int			handle_stashing(t_shell *sh, char **split_str);
int			is_valid_env_name_sub(char *arg);
int			are_args_stashable(char **args);
int			add_new_stash_var(t_shell *sh, char **split_str);

	// ms_strs_utils.c
size_t		ft_strslen(char **strs);
int			ft_strstolist(t_list **list, char **strs,
				size_t nb_strs, char delim);
char		**ft_strschr(char **strs, char c, int forbidden_pos);
char		**ft_strsdup(char **strs);

/*Yahyas's function*/
t_pipeline	*build_pipeline_from_tokens(char **tokens);
void		free_cmds_files_and_limiter(t_commands *cmd);
void		free_pipeline(t_pipeline *p);
void		exec_with_redirection(t_pipeline *cmd, char **env, t_shell *sh);
int			exec_echo_case(t_shell *sh, char **argv);
int			exec_cmd(t_shell *sh, char *cmd_path, char **env, char **argv);
void		exec_redir_cmd(t_pipeline *cmd, char **env, t_shell *sh);
void		execute_command(t_pipeline *cmd, char **env, t_shell *sh);
t_pipeline	*parse_redirection_only(char **tokens);
void		print_pipeline(t_pipeline *p);
void		run_pipes_with_no_redir(t_pipeline *p, char **env);
void		run_pipeline_with_redir(t_pipeline *p, char **env, t_shell *sh);
char		*get_cmd_path(char *cmd, char **envp);
int			validate_and_exec_command(char **argv, char **envp, t_shell *sh);
void		setup_redirections(int in_fd, int out_fd);
int			exec_parse_redir_loop(t_parse_redir_ctx *ctx, char **tokens);
void		append_token_to_argv(char **argv, char *token, int *arg_i);
int			handle_redirection_token(t_pipeline *p, char **tokens, int *i);
bool		handle_redirection_tokens(char **tokens, int *i,
				t_pipeline *p, int cmd_index);
typedef enum e_cmd_type
{
	BASIC,
	REDIR_ONLY,
	PIPELINE,
	MIXED_INVALID,
	PIPELINE_WITH_RED,
	HERE_DOC
}	t_cmd_type;
typedef struct s_redir
{
	char			*file;
	t_cmd_type		type;
	struct s_redir	*next;
}	t_redir;

bool		is_builtin(const char *cmd);
t_cmd_type	classify_command(char **tokens);
int			count_pipes(char **tokens);
void		parse_and_build_pipeline(t_pipeline *pipeline, char **tokens);
bool		has_heredoc(t_pipeline *p);
char		**extract_tokens(char **tokens, int start, int end);
t_commands	parse_command(char **tokens);
void		free_command(t_commands *cmd);
void		free_tokens(char **tokens);
void		run_pipeline_basic_pipeline(t_pipeline *p, char **env, t_shell *sh);
int			count_cmds(char **tokens);
int			count_command_tokens(char **tokens, int start);
int			exec_builtin_in_child(char **argv, t_shell *sh);
int			cmd_echo_x(char **argv);
bool		validate_cd_command(char **argv, t_shell *sh);
bool		validate_pipeline_commands(t_pipeline *p, t_shell *sh);
int			validate_all_non_builtins(t_pipeline *p, char **env, t_shell *sh);
void		open_pipe_if_needed(int i, int cmd_count, int pipe_fd[2]);
void		handle_cat_no_args(t_commands *cmd, int i, int total);
int			is_token_control_char(char *token, char ctrl_char);
char		*shell_find_cmd_path(char *cmd, char **paths);
int			get_output_flags(int append);
int			open_fd(const char *filename, int flags, t_shell *sh);
void		close_fds(int in, int out);
void		handle_redir_only(t_shell *sh, char **env);
void		handle_basic(t_shell *sh);
void		handle_pipeline(t_shell *sh, char **env);
void		restore_quoted_spaces(char *str);
bool		validate_all_redirections(char **tokens, t_shell *sh);
int			validate_direct_path(char **argv, t_shell *sh);
int			validate_in_path(char **argv, char **envp, t_shell *sh);
void		run_pipeline_with_redir(t_pipeline *p, char **env, t_shell *sh);
void		wait_for_pipeline(t_pipeline *p, pid_t last_pid, t_shell *sh);
void		handle_parent_pipe_closing(t_pipeline_loop_context *ctx);
void		execute_child_pipeline_cmd(t_pipeline_loop_context *ctx);
int			open_redirection_fds_mixed(t_commands *cmd,
				int *in_fd, int *out_fd, t_shell *sh);
t_cmd_type	check_cmd_class(t_cmd_flags flags);
int			check_pipe(char **tokens, int i, t_cmd_flags *flags);
int			check_heredoc(char **tokens, int *i, t_cmd_flags *flags);
int			check_redirection(char **tokens, int *i, t_cmd_flags *flags);
void		check_normal_cmd(char **tokens, int i, t_cmd_flags *flags);
int			handle_pipe_token(char **tokens, int *i, int *current_cmd);
int			init_argv_if_needed(t_pipeline *p, char **tokens,
				int i, int current_cmd);
void		cleanup_exec(t_parse_redir_ctx	ctx);
void		setup_redirections(int in_fd, int out_fd);
void		cleanup_pipeline_on_error(t_pipeline *p,
				t_commands *cmd, char **argv);
int			handle_redir_in(t_pipeline *p, char **tokens, int *i);
int			handle_redir_out(t_pipeline *p, char **tokens, int *i);
int			handle_append(t_pipeline *p, char **tokens, int *i);
char		**extract_command_args(char **tokens, int *i, int count);
int			control_token(char *token);
int			count_args(char **tokens);
bool		handle_redirection_parsing(t_parse_context *parse);
bool		handle_redir_in_parsing(t_commands *cmd,
				t_parse_state *fd, char **tokens, int *i);
bool		parse_tokens_loop(t_commands *cmd,
				t_parse_state *fd, char **tokens);
void		init_ctx_pipeline_one(t_exec_context *ctx,
				int prev_fd, int pipe_fd[2], char **env);
void		init_ctx_pipeline_two(t_exec_context *ctx,
				t_shell *sh, t_pipeline *p, int i);
char		*get_cmd_path_from_list(char *cmd, t_list *env_list);
char		**env_list_to_array(t_list *env_list);
void		free_env_array(char **env_array);
int			case_redir_pipeline(t_shell *sh, char **env_arr);
void		set_signals_to_default(void);
void		print_cmd_not_found_and_free(char *cmd_path, char *cmd_name);
void		set_signals_to_ignore(void);
void		exit_if_redirection_failed(int redir_status, int is_last_cmd);
void		init_ctx(t_pipeline *p, char **env,
				t_shell *sh, t_pipeline_loop_context *ctx);
int			pipeline_fork_loop(t_pipeline *p, char **env, t_shell *sh);
void		setup_redirections_red(t_pipeline_loop_context *ctx);
void		setup_child_fds_red(t_pipeline_loop_context *ctx);
void		copy_with_spaces(char *new_str, const char *str, char special);
int			count_substring_occurrences(const char *line,
				const char *str, int op_len);
int			count_extra_spaces(const char *str, char special);
void		increase_str(char *new_str, char special, int *j);
bool		check_consecutive_redir(char **args);
int			loop_case_empty_str(t_shell *sh);
int			basic_case_empty_str(t_shell *sh);
int			basic_case_empty_var(t_shell *sh);
void		protect_spaces_in_assignements(char *str);
void		restore_protected_spaces(char **args);

// bool		handle_builtin_if_needed(t_commands *cmd, t_shell *sh);
// void		exec_external_cmd(t_commands *cmd, char **env);
// void		execute_child_pipeline_cmd(t_pipeline *p, char **env, t_shell *sh,
// 	int i, int prev_fd, int pipe_fd[2]);
#endif

# Minishell

Minishell is a simple Unix shell implemented in C. It replicates basic shell behavior, allowing users to execute commands, manage environment variables, and handle input/output redirection and pipelines.

## Features

- **Prompt**: Displays a customizable prompt and waits for user input.
- **Command Execution**: Runs built-in and external commands.
- **Built-in Commands**: Supports commands like `cd`, `echo`, `pwd`, `export`, `unset`, `env`, and `exit`.
- **Pipelines**: Handles multiple commands connected with pipes (`|`).
- **Redirections**: Supports input (`<`), output (`>`), heredoc (`<<`) and append (`>>`) redirections.
- **Environment Variables**: Manages and expands environment variables.
- **Signal Handling**: Handles signals such as `Ctrl+C` and `Ctrl+D` gracefully.
- **Error Handling**: Provides informative error messages for invalid commands or syntax.

## Getting Started

### Prerequisites

- GCC
- Make
- Unix-like operating system (Linux)

### Building

Clone the repository and build the project:

```sh
git clone https://github.com/yahyaeb/minishell.git
cd minishell
make
```

### Usage

Run the shell:

```sh
./minishell
```

Type commands as you would in a standard shell. Use `exit` to quit.

## Example

```sh
minishell$ echo Hello, World!
Hello, World!
minishell$ export NAME=Yahia
minishell$ echo $NAME
Yahia
minishell$ ls -l | grep minishell > result.txt
minishell$ cat result.txt
```

## Project Structure

- `src/` – Source code files
- `inc/` – Header files
- `pipex_ms/` – Pipex and heredoc logic reused in Minishell
- `pipex_ms/` –  libraries
- `Makefile` – Custom C libraries used throughout the project

## Authors

- Yahia Elboukili ([LinkedIn](https://www.linkedin.com/in/yahia-elboukili/))
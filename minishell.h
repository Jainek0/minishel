/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:43:09 by thcaquet          #+#    #+#             */
/*   Updated: 2025/05/02 18:55:28 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <readline/readline.h>
# include "libft/src/libft.h"

#  define ERROR_ARGC "ERROR : NO ARGUMET VALID\n"
#  define ERROR_MALLOC "ERROR : MALLOC FAILL\n"
#  define ERROR_GETWCD "ERROR : GETWCD\n"
#  define ERROR_GETWCD "ERROR : GETWCD\n"

#  define ERROR_EXECVE "ERROR : EXECVE\n"
#  define ERROR_EXEC_PATH "No such file or directory\n"
#  define ERROR_EXEC_CMD "Command not found\n"
#  define ERROR_PERM "ERROR : PERME\n"

#  define ERROR_FILE_PERM "Permission denied\n"
#  define ERROR_FILE_PATH "No such file or directory\n"



#  define CD_TOO_MANY_ARG "bash: cd: too many arguments\n"
#  define CD_NO_DIRECTORY "bash: cd: No such file or directory\n"
#  define CD_NO_PERM "bash: cd: Permission denied\n"
#  define CD_HOME_NO_SET "bash: cd: HOME not set\n"
#  define CD_OLDPWD_NO_SET "bash: cd: OLDPWD not set\n"

#  define MALLOC_FAILURE "ERROR : MALLOC FAILURE\n"
#  define FORK_FAILURE "ERROR : FORK FAILURE\n"
#  define OPEN_FAILURE "ERROR : OPEN FAILURE\n"



typedef struct s_envlist
{
	char				*at;
	struct s_envlist	*next;
}	t_envlist;

typdef struct s_fd
{
	int	in;
	int	out;
}	t_fd

typedef struct	s_data
{
	t_envlist	*start;
	t_envlist	*end;
	t_fd		std;
	t_fd		fd;
	char		*line;
	char		*ex;
	int			error;
	int			pipe;
	pid_t		pid_fork;
}	t_data;

void	mini_pwd(t_data *data);
void	mini_cd(t_data *data, char **cmd);
void	mini_echo(t_data data, char **cmd);
void	mini_execve(t_data *data, char **cmd);

char	*env_get_search(t_data *data, char *re);
char	*env_dup_search(t_data *data, char *re);
char	**env_w_search(t_data *data, char *re);
char	*env_exanp(char *str);

void    mini_liberate_all(t_data *data, char *msg, int err);
void    mini_free_envlist(t_envlist *start);
void	put_error(t_data *data, char *msg, int error);

char	**lst_to_tab(t_data *data);
void	free_data(t_data *data);
void	free_tab(char **tab);

void	set_envs(t_data *data, char **envp); //tmp
void	mini_env(t_data *data);
t_data	set_data(void);
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 19:12:12 by thcaquet          #+#    #+#             */
/*   Updated: 2025/04/11 19:26:14 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include "libft/src/libft.h"

#  define ERROR_ARGC "ERROR : NO ARGUMET VALID\n"
#  define ERROR_MALLOC "ERROR : MALLOC FAILL\n"

typedef struct s_node
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				status;
	struct s_node	*next;
}	t_node;

typedef struct s_tail
{
	t_node	*start;
	t_node	*end;
	int		len;
}	t_tail;

typedef struct s_data
{
	int		error;
	char	**envp;
	char	*line;
	t_tail	cmd;
	t_tail	envs;
}	t_data;

t_node	*mini_lst_add_new(t_tail *tail, unsigned char *str1, unsigned char *str2);
void	mini_lst_clear(t_node **lst);

void	set_envs(t_tail *envs, char **envp);

void    print_export(t_data *data);


int	ft_strcmp(unsigned char *s1, unsigned char *s2); //tmp

#endif
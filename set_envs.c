/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_envs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:30:04 by thcaquet          #+#    #+#             */
/*   Updated: 2025/04/11 17:45:55 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	set_envs_error(t_tail *envs)
{
	perror(ERROR_MALLOC);
	mini_lst_clear(&envs->start);
	return (1);
}

static unsigned char	*set_str1(char *str, int *j)
{
	unsigned char	*str1;

	*j = 0;
	while(str[*j] && str[*j] != '=')
		(*j)++;
	str1 = malloc(*j + 1);
	if (!str1)
		return (0);
	*j = 0;
	while(str[*j] && str[*j] != '=')
	{
		str1[*j] = str[*j];
		(*j)++;
	}
	str1[*j] = 0;
	return (str1);
}

void	set_envs(t_tail *envs, char **envp)
{
	int 			i;
	int				j;
	unsigned char	*str1;
	unsigned char	*str2;

	i = -1;
	j = 0;
	envs->end = 0;
	envs->start = 0;
	envs->end = 0;
	if (!envp)
		return ;
	while (envp[++i])
	{
		str1 = set_str1(envp[i], &j);
		if (!str1)
			exit(set_envs_error(envs));
		if (envp[i][++j])
			str2 = (unsigned char *) ft_strdup(&envp[i][j]);
		else
			str2 = 0;
		mini_lst_add_new(envs, str1, str2);
		if (!envs->end)
			exit(set_envs_error(envs));
	}
}

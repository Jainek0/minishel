/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 17:17:08 by thcaquet          #+#    #+#             */
/*   Updated: 2025/04/11 19:26:27 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	g_status = 1;

int main(int ac, char **av, char **envp)
{
	t_data	data;

	(void)av;
	(void)envp;
	if (ac > 1)
	{
		printf("%s\n", ERROR_ARGC);
		return(0);
	}
	set_envs(&data.envs, envp);
	print_export(&data);
	while (g_status)
	{
		data.line = readline("minishell> ");
		if (data.line)
		{
			printf("%s\n", data.line);
			free(data.line);
		}
	}
	return (0);
}
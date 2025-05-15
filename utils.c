/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 16:20:16 by thcaquet          #+#    #+#             */
/*   Updated: 2025/05/01 20:00:49 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

size_t	lstlen_chr(t_envlist *node, char c)
{
	size_t	i;

	i = 0;
	while (node)
	{
		if (ft_strchr(node->at, c))
			i++;
		node = node->next;
	}
	return (i);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

char	**lst_to_tab(t_data *data)
{
	int			i;
	char		**new;
	t_envlist	*node;

	i = 0;
	node = data->start;
	new = malloc(sizeof(char *) * (lstlen_chr(node, '=') + 1));
	if (!new)
		mini_liberate_all(data, FAILURE_MALLOC, 1);
	while (node)
	{
		if (ft_strchr(node->at, '='))
		{
			new[i] = ft_strdup(node->at);
			if (!new[i])
			{
				free_tab(new);
				mini_liberate_all(data, FAILURE_MALLOC, 1);
			}
			i++;
		}
		node = node->next;
	}
	new[i] = 0;
	return (new);
}

void	put_error(t_data *data, char *msg, int error)
{
	ft_putstr_fd(msg, 2);
	data->error = error;
}

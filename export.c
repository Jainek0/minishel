/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:48:20 by thcaquet          #+#    #+#             */
/*   Updated: 2025/04/11 19:27:09 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	env_sort(t_tail *tail)
{
	unsigned char	*str1;
	unsigned char	*str2;
	t_node			*node;
	t_node			*next;

	node = tail->start;
	while (node)
	{
		next = node->next;
		if (next && ft_strcmp(node->str1, next->str1) > 0)
		{
			str1 = node->str1;
			str2 = node->str2;
			node->str1 = next->str1;
			node->str2 = next->str2;
			next->str1 = str1;
			next->str2 = str2;
			node = tail->start;
		}
		else
			node = next;
	}
}

void    print_export(t_data *data)
{
	t_node *node;

	node = data->envs->start;
	env_sort(tail);
	while (node)
	{
		if (node->str1 && ft_strcmp(node->str1, (unsigned char *) "_"))
		{
			printf("declare -x \"%s\"", node->str1);
			if (node->str2)
				printf("=%s", node->str2);
			printf("\n");
		}
		node = node->next;
	}
	data->error = 0;
}

void	add_export(t_data *data, t_node *node)
{
	t_node	*next;
	int		i;
	int		b;

	while(node)
	{
		i = 0;
		b = 1;
		while(node->str1[i])
		{
			if (node->str1[i] == "=")
			{
				add_env_p(data, node);
				b = 0;
			}
			i++;
		}
		if (b)
			add_env_s(data, node);
		data->error = 0;
	}
}

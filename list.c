/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thcaquet <thcaquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 15:38:02 by thcaquet          #+#    #+#             */
/*   Updated: 2025/04/11 17:14:00 by thcaquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	mini_lst_clear(t_node **lst)
{
	t_node	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free((*lst)->str1);
		free((*lst)->str2);
		free(*lst);
		*lst = tmp;
	}
	lst = NULL;
	return ;
}

t_node	*mini_lst_add_new(t_tail *tail, unsigned char *str1, unsigned char *str2)
{
	t_node	*new;
	t_node	*tmp;

	new = malloc(sizeof(t_node));
	if (!new)
		return (0);
	new->str1 = str1;
	new->str2 = str2;
	new->next = 0;
	if (!tail->start)
		tail->start = new;
	if (tail->end)
	{
		tmp = tail->end;
		tmp->next = new;
	}
	tail->end = new;
	tail->len++;
	return (new);
}

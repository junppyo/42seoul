/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:12:17 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/25 16:50:38 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_list **l)
{
	t_list	*tmp_node;

	if (!(*l))
		return ;
	tmp_node = malloc(sizeof(t_list));
	tmp_node->content = (*l)->content;
	tmp_node->index = (*l)->index;
	(*l)->content = (*l)->next->content;
	(*l)->index = (*l)->next->index;
	(*l)->next->content = tmp_node->content;
	(*l)->next->index = tmp_node->index;
	free(tmp_node);
	ft_printf("s%c\n", (*l)->name);
}

void	p(t_list **l1, t_list **l2)
{
	t_list	*tmp_node;

	if (!(*l2))
		return ;
	if ((*l2)->name == 'a')
		(*l2)->name = 'b';
	else
		(*l2)->name = 'a';
	tmp_node = (*l2);
	if (ft_lstsize(l2) == 1)
		*l2 = NULL;
	else
	{
		(*l2)->pre->next = (*l2)->next;
		(*l2)->next->pre = (*l2)->pre;
		*l2 = (*l2)->next;
	}
	ft_lstadd_front(l1, tmp_node);
	ft_printf("p%c\n", (*l1)->name);
}

void	r(t_list **l)
{
	if (!(*l))
		return ;
	*l = (*l)->next;
	ft_printf("r%c\n", (*l)->name);
}

void	rr(t_list **l)
{
	if (!(*l))
		return ;
	*l = (*l)->pre;
	ft_printf("rr%c\n", (*l)->name);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:45:21 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/22 16:19:16 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **l)
{
	if ((*l)->content > (*l)->next->content)
		s(l);
}

void	sort_3(t_list **l)
{
	int	a;
	int	b;
	int	c;

	c = (*l)->content;
	b = (*l)->next->content;
	a = (*l)->next->next->content;
	if (a > b && b > c)
		return ;
	else if (a > c && c > b)
		s(l);
	else if (b > a && a > c)
	{
		s(l);
		r(l);
	}
	else if (b > c && c > a)
		rr(l);
	else if (c > a && a > b)
		r(l);
	else if (c > b && b > a)
	{
		s(l);
		rr(l);
	}
}

void	sort_4(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		min;
	int		cnt;

	cnt = 0;
	min = find_min(a);
	tmp = *a;
	while (tmp->content > min)
	{
		cnt++;
		tmp = tmp->next;
	}
	if (cnt >= 2)
		while (cnt++ < 4)
			rr(a);
	else
		while (cnt--)
			r(a);
	p(b, a);
	sort_3(a);
	p(a, b);
}

void	sort_5(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(a) - 3;
	while (ft_lstsize(a) - 3)
	{
		before_push(a, b, size);
		p(b, a);
		after_push(b);
	}
	sort_b(b);
	sort(a, b);
	while (ft_lstsize(b) > 0)
		p(a, b);
}

void	sort(t_list **a, t_list **b)
{
	int	size;

	size = ft_lstsize(a);
	if (size > 4)
		sort_5(a, b);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 3)
		sort_3(a);
	else if (size == 2)
		sort_2(a);
}

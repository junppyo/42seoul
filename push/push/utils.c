/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 15:16:31 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/21 15:23:36 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_min_max(t_list **l, int n)
{
	t_list	*tmp;
	int		min;
	int		max;
	int		i;
	int		size;

	tmp = *l;
	size = ft_lstsize(l);
	i = 0;
	min = n;
	max = n;
	while (i++ < size)
	{
		if (min > tmp->index)
			min = tmp->index;
		else if (max < tmp->index)
			max = tmp->index;
		tmp = tmp->next;
	}
	if (min == n)
		return (-1);
	else if (max == n)
		return (1);
	else
		return (0);
}

int	find_min(t_list **l)
{
	t_list	*tmp;
	int		min;
	int		i;

	i = 0;
	tmp = *l;
	min = tmp->content;
	while (i++ < ft_lstsize(l))
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	get_cnt(int cnt_a, int cnt_b)
{
	int	ret;

	ret = 0;
	if (cnt_a < 0)
		cnt_a *= -1;
	if (cnt_b < 0)
		cnt_b *= -1;
	ret = cnt_a + cnt_b;
	return (ret);
}

void	do_oper(t_list **l, int cnt)
{
	if (cnt > 0)
		while (cnt-- != 0)
			r(l);
	else
		while (cnt++ != 0)
			rr(l);
}

void	sort_b(t_list **l)
{
	t_list	*tmp;
	int		cnt;
	int		max;

	cnt = 0;
	tmp = *l;
	max = tmp->index;
	while (cnt++ < ft_lstsize(l))
	{
		if (max < tmp->index)
			max = tmp->index;
		tmp = tmp->next;
	}
	cnt = calculate_a(l, max);
	do_oper(l, cnt);
}

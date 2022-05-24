/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:15:12 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/22 21:57:46 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_a(t_list **l, int n)
{
	t_list	*tmp;
	int		cnt;
	int		size;

	tmp = *l;
	size = ft_lstsize(l);
	cnt = 0;
	while (cnt < size)
	{
		if (tmp->index == n)
			break ;
		cnt++;
		tmp = tmp->next;
	}
	if (cnt > size / 2)
		return ((size - cnt) * -1);
	else
		return (cnt);
}

int	calculate_b(t_list **l, int n)
{
	t_list	*tmp;
	int		cnt;
	int		size;

	tmp = *l;
	cnt = 0;
	size = ft_lstsize(l);
	if (is_min_max(l, n) != 0)
		return (find_max_loc(l));
	while (cnt < size)
	{
		if (tmp->index > n && tmp->next->index < n)
		{
			cnt++;
			break ;
		}
		tmp = tmp->next;
		cnt++;
	}
	if (cnt == size)
		return (0);
	else if (cnt > size / 2)
		return ((size - cnt) * -1);
	else
		return (cnt);
}

int	find_element(t_list **a, t_list **b, int size)
{
	t_list	*tmp;
	int		cnt;
	int		i;
	int		min;
	int		n;

	tmp = *a;
	min = 2147483647;
	i = 0;
	while (i++ < ft_lstsize(a))
	{
		if (tmp->index < size)
		{
			cnt = get_cnt(calculate_a(a, tmp->index), \
					calculate_b(b, tmp->index));
			if (min > cnt)
			{
				min = cnt;
				n = tmp->index;
			}
		}
		tmp = tmp->next;
	}
	return (n);
}

void	before_push(t_list **a, t_list **b, int size)
{
	int		n;

	n = find_element(a, b, size);
	do_oper(a, calculate_a(a, n));
	if (*b == NULL)
		return ;
	do_oper(b, calculate_b(b, n));
}

void	after_push(t_list **l)
{
	t_list	*tmp;
	int		cnt;

	tmp = *l;
	if (ft_lstsize(l) < 2)
		return ;
	if (is_min_max(l, tmp->index) == -1)
	{
		r(l);
		return ;
	}
	else
		return ;
	cnt = 0;
}	

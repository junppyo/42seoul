/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:22:45 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/22 16:00:02 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_list *l)
{
	t_list	*tmp;
	int		cnt;

	cnt = 0;
	tmp = l;
	while (cnt++ < ft_lstsize(&l) - 1)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	chk_dup(t_list *l)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;
	int		j;

	tmp1 = l;
	i = 0;
	while (i++ < ft_lstsize(&l))
	{
		j = 0;
		tmp2 = tmp1->next;
		while (j++ < ft_lstsize(&l) - 1)
		{
			if (tmp1->content == tmp2->content)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
	}
	return (0);
}

int	chk_arg(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9') && s[i] != ' ' && s[0] != '-')
			return (1);
		i++;
	}
	return (0);
}

int	chk_int(long long n)
{
	if (n > 2147483647 || n < -2147483648)
		return (1);
	return (0);
}

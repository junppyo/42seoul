/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 14:48:04 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/25 15:48:11 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max_loc(t_list **l)
{
	t_list	*tmp;
	int		max;
	int		i;
	int		loc;

	i = -1;
	loc = 0;
	tmp = *l;
	if (tmp == NULL)
		return (0);
	max = tmp->index;
	while (++i < ft_lstsize(l))
	{
		if (tmp->index > max)
		{
			max = tmp->index;
			loc = i;
		}
		tmp = tmp->next;
	}
	if (loc > ft_lstsize(l) / 2)
		return ((ft_lstsize(l) - loc) * -1);
	else
		return (loc);
}

void	free_all(long long *num_list, char **split_str, int cnt)
{
	while (cnt--)
		free(split_str[cnt]);
	free(split_str);
	free(num_list);
}

int	split_init(char *s, char ***split_str, long long **num_list)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 1;
	while (s[i])
		if (s[i++] == ' ')
			cnt++;
	*num_list = malloc(sizeof(long long) * cnt);
	*split_str = ft_split(s, ' ');
	return (cnt);
}

int	list_split(char *s, t_list **l)
{
	char		**split_str;
	long long	*num_list;
	int			cnt;
	int			i;

	num_list = NULL;
	split_str = NULL;
	cnt = split_init(s, &split_str, &num_list);
	i = 0;
	while (--cnt >= 0)
	{
		num_list[i] = ft_atoi(split_str[cnt]);
		if (chk_int(num_list[i++]))
		{
			free_all(num_list, split_str, i);
			return (1);
		}
		free(split_str[cnt]);
	}
	free(split_str);
	while (++cnt < i)
		ft_lstadd_front(l, ft_lstnew((int)num_list[cnt]));
	free(num_list);
	return (0);
}

void	make_index(t_list **l)
{
	t_list	*tmp1;
	t_list	*tmp2;
	int		i;
	int		j;
	int		cnt;

	tmp1 = *l;
	i = 0;
	while (i++ < ft_lstsize(l))
	{
		cnt = 0;
		j = 0;
		tmp2 = *l;
		while (j++ < ft_lstsize(l))
		{
			if (tmp1->content > tmp2->content)
				cnt++;
			tmp2 = tmp2->next;
		}
		tmp1->index = cnt;
		tmp1 = tmp1->next;
	}
}

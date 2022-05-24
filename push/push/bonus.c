/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:53:40 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/25 16:53:45 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus.h"

int	operation1(char *s, t_list **a, t_list **b)
{
	if (s[0] == 'r' && (ft_strlen(s) == 3 || ft_strlen(s) == 4))
	{
		if (s[1] == 'r' && ft_strlen(s) == 4)
		{
			if (s[2] == 'a')
				rr(a);
			else if (s[2] == 'b')
				rr(b);
			else if (s[2] == 'r')
			{
				rr(a);
				rr(b);
			}
		}
		else if (s[1] == 'a' && ft_strlen(s) == 3)
			r(a);
		else if (s[1] == 'b' && ft_strlen(s) == 3)
			r(b);
		else
			return (1);
	}
	else
		return (operation2(s, a, b));
	return (0);
}

int	operation2(char *str, t_list **a, t_list **b)
{
	if ((str[0] == 's' || str[0] == 'p') && ft_strlen(str) == 3)
	{
		if (str[0] == 's' && str[1] == 'a')
			s(a);
		else if (str[0] == 's' && str[1] == 'b')
			s(b);
		else if (str[0] == 's' && str[1] == 's')
		{
			s(a);
			s(b);
		}
		else if (str[0] == 'p' && str[1] == 'a')
			p(a, b);
		else if (str[0] == 'p' && str[1] == 'b')
			p(b, a);
		else
			return (1);
	}
	else
		return (1);
	return (0);
}

int	read_command(t_list **a, t_list **b)
{
	char	*s;

	while (1)
	{
		s = get_next_line(0);
		if (s == NULL)
			break ;
		if (operation1(s, a, b))
		{
			write(2, "Error\n", 6);
			return (1);
		}
		free(s);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;

	if (argc == 1)
		return (0);
	while (argc-- > 1)
	{
		if (chk_arg(argv[argc]) || list_split(argv[argc], &a) || chk_dup(a))
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	if (read_command(&a, &b))
		return (0);
	if (!sorted(a) || ft_lstsize(&b) != 0)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:50:13 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/25 15:52:45 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*a;
	t_list	*b;
	int		i;

	if (argc < 2)
		return (0);
	i = argc;
	a = NULL;
	b = NULL;
	while (--i > 0)
	{
		if (chk_arg(argv[i]) || list_split(argv[i], &a) || chk_dup(a))
		{
			write(2, "Error\n", 6);
			return (0);
		}
	}
	if (sorted(a))
		return (0);
	make_index(&a);
	sort(&a, &b);
	return (0);
}

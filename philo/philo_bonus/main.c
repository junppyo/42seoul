/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:16:48 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/24 15:01:14 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	chk(int argc, char *argv[])
{
	int	i;

	if (argc != 5 && argc != 6)
		return (1);
	i = 1;
	if (ft_atoi(argv[1]) <= 0)
		return (1);
	while (i < argc)
	{
		if (ft_atoi(argv[i]) < 0)
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_table	*table;

	if (chk(argc, argv))
		return (0);
	table = make_table(argc, argv);
	if (!table)
	{
		printf("init fail\n");
		return (0);
	}
	if (dinner(table))
	{
		printf("process create fail\n");
		return (0);
	}
	return (0);
}	

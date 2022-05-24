/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:39:41 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/24 15:03:59 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	**make_philo(t_table *table)
{
	t_philo	**ret;
	int		i;

	ret = malloc(sizeof(t_philo *) * table->philo_num);
	if (!ret)
		return (0);
	i = 0;
	while (i < table->philo_num)
	{
		ret[i] = malloc(sizeof(t_philo));
		if (!ret[i])
			return (0);
		ret[i]->name = i + 1;
		ret[i]->each_eat = 0;
		ret[i]->dead = 0;
		ret[i]->table = table;
		ret[i]->last_eat = ret[i]->table->start_time;
		i++;
	}
	return (ret);
}

t_table	*parse_arg(int argc, char *argv[])
{
	t_table	*ret;

	ret = malloc(sizeof(t_table));
	if (!ret)
		return (0);
	ret->philo_num = ft_atoi(argv[1]);
	ret->time_to_die = ft_atoi(argv[2]);
	ret->time_to_eat = ft_atoi(argv[3]);
	ret->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		ret->eat_cnt = ft_atoi(argv[5]);
	else
		ret->eat_cnt = -1;
	return (ret);
}

t_table	*make_table(int argc, char *argv[])
{
	t_table	*ret;

	ret = parse_arg(argc, argv);
	if (!ret)
		return (0);
	ret->full_cnt = 0;
	ret->start_time = get_time();
	ret->dead = 0;
	ret->printing = sem_open("print", O_CREAT, 0644, 1);
	if (ret->printing < 0)
		return (0);
	ret->fork = sem_open("fork", O_CREAT, 0644, ret->philo_num);
	if (ret->fork < 0)
		return (0);
	sem_unlink("print");
	sem_unlink("fork");
	sem_unlink("life");
	ret->philo = make_philo(ret);
	if (!ret->philo)
		return (0);
	return (ret);
}

int	dinner(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_num)
	{
		table->philo[i]->pid = fork();
		if (table->philo[i]->pid == 0)
		{
			start_dinner(table->philo[i]);
			return (0);
		}
		else if (table->philo[i]->pid < 0)
			return (1);
		i++;
	}
	chk_live(table);
	return (0);
}

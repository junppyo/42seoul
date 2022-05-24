/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:15:34 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/21 16:53:59 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grap_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print(philo, "philo has taken fork");
	pthread_mutex_lock(philo->right_fork);
	print(philo, "philo has taken fork");
}

void	*start_dinner(void *phil)
{
	long long	now;
	t_philo		*philo;
	int			n;

	philo = (t_philo *) phil;
	if (philo->name % 2 == 0)
		usleep(300);
	while (!philo->table->dead)
	{
		grap_fork(philo);
		eating(philo);
		sleeping(philo);
	}
	return (0);
}

void	eating(t_philo *philo)
{
	print(philo, "is eating");
	usleeps(philo->table->time_to_eat);
	if (philo->table->dead)
		return ;
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	philo->last_eat = get_time();
	philo->each_eat++;
}

void	chk_live(t_table *table)
{
	int			i;
	long long	now;

	i = 0;
	while (!table->dead)
	{
		now = get_time();
		if (table->time_to_die < now - table->philo[i]->last_eat)
		{
			make_die(table);
			printf("%lld\t%d is died\n", now - table->start_time, i + 1);
		}
		if (table->philo[i]->each_eat == table->eat_cnt && table->eat_cnt != -1)
		{
			table->philo[i]->each_eat++;
			if (++table->full_cnt == table->philo_num)
				make_die(table);
		}
		if (++i == table->philo_num)
			i = 0;
	}
}

void	sleeping(t_philo *philo)
{
	print(philo, "is sleeping");
	usleeps(philo->table->time_to_sleep);
	print(philo, "is thinking");
}

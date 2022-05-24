/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dinner.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 20:15:34 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/22 15:17:29 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	grap_fork(t_philo *philo)
{
	sem_wait(philo->table->fork);
	print(philo, "philo has taken fork");
	sem_wait(philo->table->fork);
	print(philo, "philo has taken fork");
}

int	start_dinner(t_philo *philo)
{
	if (philo->name % 2 == 0)
		usleep(300);
	philo->monitor = fork();
	if (philo->monitor == 0)
	{
		monitor(philo);
		return (0);
	}
	while (!philo->table->dead)
	{
		grap_fork(philo);
		eating(philo);
		kill(philo->monitor, SIGKILL);
		philo->monitor = fork();
		if (philo->monitor == 0)
		{
			monitor(philo);
			return (0);
		}
		sleeping(philo);
	}
	kill(philo->monitor, SIGKILL);
	return (1);
}

void	eating(t_philo *philo)
{
	print(philo, "is eating");
	usleeps(philo->table->time_to_eat);
	sem_post(philo->table->fork);
	sem_post(philo->table->fork);
	philo->last_eat = get_time();
	if (++philo->each_eat == philo->table->eat_cnt)
		philo->table->dead = 2;
}

void	sleeping(t_philo *philo)
{
	print(philo, "is sleeping");
	if (philo->each_eat == philo->table->eat_cnt)
		return ;
	usleeps(philo->table->time_to_sleep);
	print(philo, "is thinking");
}

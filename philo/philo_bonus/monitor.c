/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 20:12:10 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/23 14:46:31 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	chk_live(t_table *table)
{
	int			i;
	int			status;

	i = 0;
	while (i < table->philo_num)
	{
		waitpid(-1, &status, 0);
		i++;
	}
}

void	monitor(t_philo *philo)
{
	long long	now;

	now = get_time();
	if (philo->table->dead)
		return ;
	while (philo->table->time_to_die > now - philo->last_eat)
	{
		now = get_time();
	}
	if ((int) sem_open("life", O_CREAT | O_EXCL, 0644, 1) != -1)
		printf("%lld\t%d %s\n", get_time() - philo->table->start_time,
			philo->name, "is died");
}

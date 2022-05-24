/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:41:59 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/24 15:05:06 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	thread_free(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_num)
		pthread_detach(table->philo[i++]->p_thread);
}

void	print(t_philo *philo, char *s)
{
	if (philo->table->dead)
		return ;
	pthread_mutex_lock(&philo->table->printing);
	printf("%lld\t", get_time() - philo->table->start_time);
	printf("%d %s\n", philo->name, s);
	pthread_mutex_unlock(&philo->table->printing);
}

void	usleeps(int n)
{
	long long	start;
	long long	now;

	start = get_time();
	now = get_time();
	while (get_time() - start < n)
		usleep(100);
}

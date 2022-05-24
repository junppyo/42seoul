/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:41:59 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/24 15:04:32 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	print(t_philo *philo, char *s)
{
	sem_t		*sem;

	sem_wait(philo->table->printing);
	sem = sem_open("life", O_CREAT | O_EXCL, 0644, 1);
	if ((int) sem == -1)
	{
		philo->table->dead = 1;
		sem_post(philo->table->printing);
		sem_close(philo->table->printing);
	}
	if (philo->table->dead == 1)
		return ;
	printf("%lld\t", get_time() - philo->table->start_time);
	printf("%d %s\n", philo->name, s);
	sem_unlink("life");
	sem_close(sem);
	sem_post(philo->table->printing);
}

void	usleeps(int n)
{
	long long	start;
	long long	now;

	start = get_time();
	now = get_time();
	while (get_time() - start < n)
		usleep(50);
}

int	chk_die(void)
{
	sem_t	*ret;

	ret = sem_open("life", O_CREAT | O_EXCL, 0644, 1);
	sem_unlink("life");
	if ((int) ret == -1)
		return (1);
	else
	{
		sem_close(ret);
		return (0);
	}
}

void	sem_free(t_table *table)
{
	sem_close(table->fork);
	sem_close(table->printing);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 15:54:57 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/19 15:31:12 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	make_die(t_table *table)
{
	int	i;

	i = -1;
	table->dead = 1;
	while (++i < table->philo_num)
	{
		pthread_mutex_unlock(table->fork[i]);
		pthread_mutex_destroy(table->fork[i]);
	}
	pthread_mutex_unlock(&table->printing);
	pthread_mutex_destroy(&table->printing);
}

static int	get_size(int n)
{
	int	ret;

	ret = 0;
	while (n > 0)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

char	*ft_itoa(int n)
{
	char	*ret;
	int		cnt;

	cnt = get_size(n);
	ret = malloc(sizeof(char) * (cnt + 1));
	if (ret == NULL)
		return (0);
	ret[cnt--] = '\0';
	while (n > 0)
	{
		ret[cnt--] = n % 10 + '0';
		n /= 10;
	}
	return (ret);
}

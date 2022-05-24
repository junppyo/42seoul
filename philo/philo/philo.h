/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:37:36 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/17 20:10:44 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

struct	s_table;

typedef struct s_philo
{
	pthread_t		p_thread;
	int				name;
	int				each_eat;
	long long		last_eat;
	int				dead;
	struct s_table	*table;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_table
{
	int				dead;
	long long		start_time;
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_cnt;
	int				full_cnt;
	t_philo			**philo;
	pthread_mutex_t	**fork;
	pthread_mutex_t	printing;
}	t_table;

int			ft_atoi(const char *str);
long long	get_time(void);
void		usleeps(int n);
void		thread_free(t_table *table);
void		print(t_philo *philo, char *s);
void		make_die(t_table *table);
int			chk(int argc, char *argv[]);
t_philo		**make_philo(t_table *table);
t_table		*make_table(int argc, char *argv[]);

int			dinner(t_table *table);
void		*start_dinner(void *philo);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		chk_live(t_table *table);

#endif

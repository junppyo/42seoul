/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:37:36 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/22 14:20:00 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <semaphore.h>
# include <signal.h>

struct	s_table;

typedef struct s_philo
{
	pid_t			pid;
	pid_t			monitor;
	int				name;
	int				each_eat;
	long long		last_eat;
	int				dead;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int			dead;
	long long	start_time;
	int			philo_num;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			eat_cnt;
	int			full_cnt;
	t_philo		**philo;
	sem_t		*fork;
	sem_t		*printing;
}	t_table;

int			ft_atoi(const char *str);
long long	get_time(void);
void		usleeps(int n);
void		sem_free(t_table *table);
void		print(t_philo *philo, char *s);
void		make_die(t_table *table);
int			chk_die(void);
int			chk(int argc, char *argv[]);
t_philo		**make_philo(t_table *table);
t_table		*make_table(int argc, char *argv[]);

int			dinner(t_table *table);
int			start_dinner(t_philo *philo);
void		eating(t_philo *philo);
void		sleeping(t_philo *philo);
void		chk_live(t_table *table);
char		*ft_itoa(int n);

void		monitor(t_philo *philo);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:57:23 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/21 14:45:21 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

unsigned int	g_c;

void	catch1(int sig)
{
	g_c = g_c << 1;
	if (sig == SIGUSR2)
		g_c |= 1;
	if (g_c >= 256)
	{
		ft_printf("%c", g_c - 256);
		g_c = 1;
	}
}

int	main(void)
{
	static struct sigaction	act;
	int						cnt;

	cnt = 0;
	g_c = 1;
	act.sa_handler = catch1;
	sigaction(SIGUSR2, &act, NULL);
	sigaction(SIGUSR1, &act, NULL);
	ft_printf("pid : %d\n", getpid());
	while (1)
		pause();
}

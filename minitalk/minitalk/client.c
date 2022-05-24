/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 20:57:31 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/14 14:30:19 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	send_message(int pid, char *msg)
{
	unsigned char	flag;
	size_t			i;
	int				j;
	size_t			len;

	flag = 128;
	i = 0;
	len = ft_strlen(msg);
	while (i < len)
	{
		j = 0;
		while (j++ < 8)
		{
			usleep(100);
			if ((flag & msg[i]) == 0)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			msg[i] = msg[i] << 1;
		}
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	if (argc < 3)
		return (0);
	i = 2;
	while (i < argc)
		send_message(ft_atoi(argv[1]), argv[i++]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:13:33 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/22 16:06:21 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v' || \
			c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

long long	ft_atoi(const char *str)
{
	int			i;
	long long	tmp;
	int			minus;

	i = 0;
	tmp = 0;
	minus = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i])
	{
		tmp = tmp * 10 + (str[i] - '0');
		i++;
	}
	return (tmp * minus);
}

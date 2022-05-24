/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:23:05 by junpkim           #+#    #+#             */
/*   Updated: 2022/03/11 16:23:07 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long long n)
{
	int	ret;

	ret = 0;
	if (n < 0)
	{
		ret++;
		n *= -1;
	}
	while (n > 0)
	{
		n /= 10;
		ret++;
	}
	return (ret);
}

static int	chk_minus(int n)
{
	if (n < 0)
		return (-1);
	else if (n == 0)
		return (0);
	return (1);
}

static char	*ret_zero(void)
{
	char	*ret;

	ret = malloc(sizeof(char) * 2);
	if (ret == NULL)
		return (0);
	ret[0] = '0';
	ret[1] = '\0';
	return (ret);
}

char	*ft_itoa(int n)
{
	char		*ret;
	int			cnt;
	long long	tmp;
	int			minus;

	minus = chk_minus(n);
	if (!minus)
		return (ret_zero());
	cnt = get_size((long long)n);
	tmp = (long long)n * minus;
	ret = malloc(sizeof(char) * (cnt + 1));
	if (ret == NULL)
		return (0);
	ret[cnt--] = '\0';
	while (tmp > 0)
	{
		ret[cnt--] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (minus == -1)
		ret[0] = '-';
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 13:05:55 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/08 13:52:33 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_format(char c, void *p)
{
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fd((int)p, 1));
	else if (c == 'u')
		return (put_unsignedn((unsigned int)p));
	else if (c == 'c')
		write(1, &p, 1);
	else if (c == 's')
		return (ft_putstr_fd((char *)p, 1));
	else if (c == 'x')
		return (put_hex_small((unsigned int)p));
	else if (c == 'X')
		return (put_hex_large((unsigned int)p));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		return (put_hex_small((unsigned long long)p) + 2);
	}
	else if (c == '%')
		write(1, "%", 1);
	return (1);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		cnt;
	int		i;

	va_start(ap, s);
	i = -1;
	cnt = 0;
	while (++i < (int)ft_strlen(s))
	{
		if (s[i] == '%')
		{
			if (s[++i] == '%')
				cnt += find_format(s[i], NULL);
			else
				cnt += find_format(s[i], va_arg(ap, void *));
		}
		else
		{
			write(1, &s[i], 1);
			cnt++;
		}
	}
	return (cnt);
}

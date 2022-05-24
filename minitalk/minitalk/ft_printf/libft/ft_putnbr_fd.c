/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:58:35 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/08 13:54:16 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_num(int n, int fd)
{
	if (n < 0)
		n *= -1;
	write(fd, &"0123456789"[n % 10], 1);
}

size_t	ft_putnbr_fd(int n, int fd)
{
	size_t	ret;

	ret = 1;
	if (n < 0)
	{
		ret++;
		write(fd, "-", 1);
		if (n <= -10)
			ret += ft_putnbr_fd(n / 10 * -1, fd);
	}
	if (n >= 10)
		ret += ft_putnbr_fd(n / 10, fd);
	write_num(n % 10, fd);
	return (ret);
}

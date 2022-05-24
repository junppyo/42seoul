/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 16:21:19 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/08 13:53:04 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_hex_small(unsigned long long n)
{
	int	ret;

	ret = 0;
	if (n >= 16)
		ret += put_hex_small(n / 16);
	write(1, &"0123456789abcdef"[n % 16], 1);
	return (1 + ret);
}

int	put_hex_large(unsigned long long n)
{
	int	ret;

	ret = 0;
	if (n >= 16)
		ret += put_hex_large(n / 16);
	write(1, &"0123456789ABCDEF"[n % 16], 1);
	return (1 + ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_unsignedn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:12:34 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/08 13:53:20 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_unsignedn(unsigned int n)
{
	int	cnt;

	cnt = 1;
	if (n >= 10)
		cnt += put_unsignedn(n / 10);
	write(1, &"0123456789"[n % 10], 1);
	return (cnt);
}

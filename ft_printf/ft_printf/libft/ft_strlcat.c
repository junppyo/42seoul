/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:09:35 by junpkim           #+#    #+#             */
/*   Updated: 2022/03/28 14:55:08 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	size_t	n;
	size_t	m;
	size_t	p;

	n = 0;
	m = 0;
	p = 0;
	while (dest[n] && n < size)
		n++;
	while (src[m])
		m++;
	while (src[p] && n + p + 1 < size)
	{
		dest[n + p] = src[p];
		p++;
	}
	if (n < size)
		dest[n + p] = '\0';
	return (n + m);
}

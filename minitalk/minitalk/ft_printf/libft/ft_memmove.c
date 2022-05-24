/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 21:05:41 by junpkim           #+#    #+#             */
/*   Updated: 2022/03/28 18:46:25 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*buf;
	const char	*s;

	buf = (char *)dst;
	s = (const char *) src;
	if (dst <= src)
	{
		ft_memcpy(dst, src, len);
	}
	else
	{
		buf += len;
		s += len;
		while (len--)
			*--buf = *--s;
	}
	return (dst);
}

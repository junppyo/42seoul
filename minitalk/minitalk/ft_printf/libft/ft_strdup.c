/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:14:41 by junpkim           #+#    #+#             */
/*   Updated: 2022/03/11 16:14:50 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ret;
	int		len;

	len = 0;
	while (src[len])
		len++;
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (ret == NULL)
		return (0);
	len = 0;
	while (src[len])
	{
		ret[len] = src[len];
		len++;
	}
	ret[len] = '\0';
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:11:32 by junpkim           #+#    #+#             */
/*   Updated: 2022/03/11 16:11:44 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n;
	size_t	m;
	size_t	i;
	size_t	j;

	n = ft_strlen(haystack);
	m = ft_strlen(needle);
	if (m == 0)
		return ((char *)haystack);
	else if (len < m)
		return (0);
	i = 0;
	while (i < len - m + 1)
	{
		j = 0;
		while (haystack[i + j] == needle[j] && j < m)
			j++;
		if (j == m)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}

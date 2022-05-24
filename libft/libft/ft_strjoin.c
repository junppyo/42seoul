/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:15:16 by junpkim           #+#    #+#             */
/*   Updated: 2022/03/14 20:55:41 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		n;
	int		m;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	n = ft_strlen(s1);
	m = ft_strlen(s2);
	ret = malloc(sizeof(char) * (n + m + 1));
	if (ret == NULL)
		return (0);
	i = -1;
	while (++i < n)
		ret[i] = s1[i];
	i = -1;
	while (++i < m)
		ret[n + i] = s2[i];
	ret[n + i] = '\0';
	return (ret);
}

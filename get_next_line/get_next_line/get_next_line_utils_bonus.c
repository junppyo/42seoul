/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:39:04 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/01 11:50:15 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int len)
{
	char	*ret;
	int		n;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (0);
	n = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * (n + len + 1));
	if (ret == NULL)
		return (0);
	i = -1;
	while (++i < n)
		ret[i] = s1[i];
	i = -1;
	while (++i < len)
		ret[n + i] = s2[i];
	ret[n + i] = '\0';
	return (ret);
}

int	chk_str(char *s)
{
	int	i;

	if (s[0] == '\0')
		return (0);
	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (s[i] == '\n')
			return (i + 1);
		else if (s[i] == '\0')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strndup(char *src, int len)
{
	char	*ret;
	int		i;

	if (len == 0)
		return (0);
	if (len == BUFFER_SIZE)
		len = ft_strlen(src);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (ret == NULL)
		return (0);
	ret[len] = '\0';
	i = 0;
	while (i < len)
	{
		ret[i] = src[i];
		i++;
	}
	return (ret);
}

char	*make_str(char *ret, char *src, int len)
{
	char	*newret;

	if (ret == NULL)
	{
		if (len == 0 && src[0] == '\0')
			return (ret);
		newret = ft_strndup(src, len);
	}
	else
	{
		newret = ft_strjoin(ret, src, len);
		free(ret);
		ret = NULL;
	}
	return (newret);
}

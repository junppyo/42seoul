/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 21:58:11 by junpkim           #+#    #+#             */
/*   Updated: 2022/03/15 14:13:02 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char s1, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

static size_t	get_start(char const *s1, char const *set)
{
	size_t	ret;

	ret = 0;
	while (isset(s1[ret], set))
		ret++;
	return (ret);
}

static size_t	get_end(char const *s1, char const *set)
{
	size_t	ret;

	ret = ft_strlen(s1) - 1;
	while (isset(s1[ret], set))
		ret--;
	return (ret);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	i;
	size_t	start;
	size_t	end;

	if (s1 == NULL)
		return (0);
	start = get_start(s1, set);
	if (start == ft_strlen(s1))
		return (ft_strdup(""));
	end = get_end(s1, set);
	ret = malloc(sizeof(char) * (end - start + 2));
	if (ret == NULL)
		return (0);
	ret[end - start + 1] = '\0';
	i = start;
	while (i <= end)
	{
		ret[i - start] = s1[i];
		i++;
	}
	return (ret);
}

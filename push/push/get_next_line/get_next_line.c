/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:33:26 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/21 17:49:00 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	load(char **ret, char **save)
{
	int		t;
	char	*tmp;

	if (*save == NULL)
		return ;
	t = chk_str(*save);
	if (t != -1 && t != (int)ft_strlen_(*save))
	{
		*ret = make_str(*ret, *save, t);
		tmp = make_str(NULL, *save + t, ft_strlen_(*save + t));
		free(*save);
		*save = NULL;
		if (tmp != NULL)
			*save = tmp;
		else
			free(tmp);
	}
	else
	{
		*ret = make_str(*ret, *save, t);
		free(*save);
		*save = NULL;
	}
}

int	malloc_s(char **s, int size)
{
	*s = (char *)malloc(sizeof(char) * size);
	if (*s == NULL)
		return (0);
	return (1);
}

void	read_fd(char **save, char **ret, int fd)
{
	char	*buf;
	int		tmp;
	int		n;

	if (malloc_s(&buf, BUFFER_SIZE + 1) == 0)
		return ;
	n = read(fd, buf, BUFFER_SIZE);
	while (n > 0)
	{
		buf[n] = '\0';
		tmp = chk_str(buf);
		if (tmp != -1)
		{
			*save = make_str(*save, &buf[tmp], ft_strlen_(&buf[tmp]));
			*ret = make_str(*ret, buf, tmp);
			break ;
		}
		*ret = make_str(*ret, buf, BUFFER_SIZE);
		free(buf);
		if (malloc_s(&buf, BUFFER_SIZE + 1) == 0)
			return ;
		n = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	buf = NULL;
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		*ret;

	if (fd < 0 || fd > OPEN_MAX)
		return (0);
	ret = NULL;
	load(&ret, &(save[fd]));
	if (ret != NULL &save[fd] != NULL)
		return (ret);
	read_fd(&save[fd], &ret, fd);
	return (ret);
}

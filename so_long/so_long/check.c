/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:23:43 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/08 21:11:37 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	chk_arg(char *s)
{
	int	i;

	i = ft_strlen(s);
	if (s[--i] != 'r' || s[--i] != 'e' || s[--i] != 'b' || s[--i] != '.')
		print_error(ARG_ERROR);
	return (0);
}

int	chk_row(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->content->row)
	{
		if (g->content->col != (int) ft_strlen(g->map[i]) - 1)
			print_error(ROW_ERROR);
		i++;
	}
	return (0);
}

int	chk_wall(t_game *g)
{
	int	i;

	i = 0;
	while (i < g->content->row)
	{
		if (g->map[i][0] != '1' || g->map[i][g->content->col] != '1')
			print_error(WALL_ERROR);
		i++;
	}
	i = 0;
	while (i < g->content->col)
	{
		if (g->map[0][i] != '1' || g->map[g->content->row - 1][i] != '1')
			print_error(WALL_ERROR);
		i++;
	}
	return (0);
}

void	chk_map(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g->content->row)
	{
		j = -1;
		while (++j < g->content->col)
		{
			if (g->map[i][j] == '0' || g->map[i][j] == '1')
				;
			else if (g->map[i][j] == 'C')
				g->content->collect_cnt++;
			else if (g->map[i][j] == 'E')
				g->content->exit_cnt++;
			else if (g->map[i][j] == 'P')
				g->content->start_cnt++;
			else
				print_error(MAP_ERROR);
		}
	}
}

int	chk_content(t_game *g)
{
	if (g->content->start_cnt != 1)
	{
		print_error(START_ERROR);
	}
	if (g->content->exit_cnt < 1)
	{
		print_error(EXIT_ERROR);
	}
	if (g->content->collect_cnt < 1)
	{
		print_error(COLLECT_ERROR);
	}
	return (0);
}

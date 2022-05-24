/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:38:35 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/08 21:14:41 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_collection(t_game *g, t_point *tmp_pos, int cnt)
{
	chk_exit(g);
	g->map[tmp_pos->y][tmp_pos->x] = 'P';
	g->player->pos->x = tmp_pos->x;
	g->player->pos->y = tmp_pos->y;
	g->content->collect_cnt--;
	ft_printf("%d\n", cnt);
}

void	chk_exit(t_game *g)
{
	if (g->player->exit_chk)
	{		
		g->map[g->player->pos->y][g->player->pos->x] = 'E';
		g->player->exit_chk = 0;
	}
	else
		g->map[g->player->pos->y][g->player->pos->x] = '0';
}

void	collision(t_game *g, t_point *tmp_pos)
{
	static int	cnt;
	char		tmp_c;

	tmp_c = g->map[tmp_pos->y][tmp_pos->x];
	if (tmp_c == '1')
		return ;
	if (tmp_c == 'C')
		get_collection(g, tmp_pos, ++cnt);
	else if (tmp_c == '0' || tmp_c == 'E')
	{
		chk_exit(g);
		if (tmp_c == 'E')
			g->player->exit_chk = 1;
		g->player->pos->x = tmp_pos->x;
		g->player->pos->y = tmp_pos->y;
		g->map[tmp_pos->y][tmp_pos->x] = 'P';
		ft_printf("%d\n", ++cnt);
		if (tmp_c == 'E' && g->content->collect_cnt == 0)
		{
			ft_printf("FINISH\n");
			exit(0);
		}
	}
}

void	move(t_game *g, int key)
{
	t_point	*tmp_pos;

	tmp_pos = (t_point *) malloc(sizeof(t_point));
	tmp_pos->x = g->player->pos->x;
	tmp_pos->y = g->player->pos->y;
	if (key == KEY_UP)
		tmp_pos->y--;
	else if (key == KEY_DOWN)
		tmp_pos->y++;
	else if (key == KEY_LEFT)
		tmp_pos->x--;
	else if (key == KEY_RIGHT)
		tmp_pos->x++;
	collision(g, tmp_pos);
	free(tmp_pos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:51:50 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/08 20:50:19 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (i < g->content->row)
	{
		j = 0;
		while (j <= g->content->col)
		{
			if (g->map[i][j] == '0')
				mlx_put_image_to_window(g->mlx->mlx_ptr,
					g->mlx->win_ptr, g->mlx->img[0], 39 * j, 44 * i);
			else
				draw_(g, g->map[i][j], i, j);
			j++;
		}
		i++;
	}
}

void	draw_(t_game *g, char c, int i, int j)
{
	if (c == 'C')
		mlx_put_image_to_window(g->mlx->mlx_ptr,
			g->mlx->win_ptr, g->mlx->img[2], 39 * j, 44 * i);
	else if (c == '1')
		mlx_put_image_to_window(g->mlx->mlx_ptr,
			g->mlx->win_ptr, g->mlx->img[1], 39 * j, 44 * i);
	else if (c == 'P')
	{
		if (g->player->exit_chk)
			mlx_put_image_to_window(g->mlx->mlx_ptr,
				g->mlx->win_ptr, g->mlx->img[3], 39 * j, 44 * i);
		else
			mlx_put_image_to_window(g->mlx->mlx_ptr,
				g->mlx->win_ptr, g->mlx->img[0], 39 * j, 44 * i);
		mlx_put_image_to_window(g->mlx->mlx_ptr,
			g->mlx->win_ptr, g->mlx->img[4], (39 * j) + 10, (44 * i) + 11);
	}
	if (c == 'E')
		mlx_put_image_to_window(g->mlx->mlx_ptr,
			g->mlx->win_ptr, g->mlx->img[3], 39 * j, 44 * i);
}

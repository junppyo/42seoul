/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 17:22:57 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/10 17:04:13 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key_code, t_game *g)
{
	if (key_code == KEY_ESC)
	{
		exit(0);
	}
	else if (key_code == KEY_UP || key_code == KEY_DOWN
		|| key_code == KEY_RIGHT || key_code == KEY_LEFT)
	{
		move(g, key_code);
		draw(g);
	}
	return (key_code);
}

int	exit_hook(int key_code)
{
	exit(0);
	return (key_code);
}

void	start_game(t_game *g, char *s)
{
	chk_arg(s);
	g->content = init_con();
	g->map = make_matrix(s, g->content);
	chk_row(g);
	chk_wall(g);
	chk_map(g);
	chk_content(g);
	g->mlx = init_t_mlx(g);
	g->player = init_player(g);
}

int	main(int argc, char *argv[])
{
	t_game		*game;

	if (argc != 2 || chk_arg(argv[1]))
		exit(1);
	game = malloc(sizeof(t_game));
	start_game(game, argv[1]);
	mlx_hook(game->mlx->win_ptr, KEY_PRESS, 0, &key_hook, game);
	mlx_hook(game->mlx->win_ptr, EVENT_EXIT, 0, &exit_hook, game);
	draw(game);
	mlx_loop(game->mlx->mlx_ptr);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 16:16:10 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/08 21:10:18 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

# include "mlx/mlx.h"
/*
# include "mlx/mlx_new_window.h"
# include "mlx/mlx_png.h"
# include "mlx/mlx_int.h"
# include "mlx/mlx_opengl.h"
*/
# define OPEN_ERROR 0 
# define ARG_ERROR 1
# define MAP_ERROR 2
# define ROW_ERROR 3
# define WALL_ERROR 4
# define START_ERROR 5
# define EXIT_ERROR 6
# define MALLOC_ERROR 7
# define COLLECT_ERROR 8

# define KEY_UP 13
# define KEY_DOWN 1
# define KEY_LEFT 0
# define KEY_RIGHT 2
# define KEY_ESC 53

# define KEY_PRESS 2
# define EVENT_EXIT 17

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_content
{
	int		col;
	int		row;
	int		collect_cnt;
	int		start_cnt;
	int		exit_cnt;
}	t_content;

typedef struct s_player
{
	t_point	*pos;
	int		exit_chk;
}	t_player;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img[5];
}	t_mlx;

typedef struct s_game
{
	t_content	*content;
	t_player	*player;
	t_mlx		*mlx;
	char		**map;
}	t_game;

t_content	*init_con(void);
int			get_row(char *s);
char		**make_matrix(char *s, t_content *content);
t_player	*init_player(t_game *game);
t_mlx		*init_t_mlx(t_game *game);

int			chk_arg(char *s);
int			chk_row(t_game *game);
int			chk_wall(t_game *game);
void		chk_map(t_game *game);
int			chk_content(t_game *game);

void		chk_exit(t_game *g);
void		move(t_game *game, int key);
void		get_collection(t_game *game, t_point *tmp_pos, int cnt);
void		collision(t_game *game, t_point *tmp_pos);

void		draw_(t_game *g, char c, int i, int j);
void		draw(t_game *g);

void		print_error(int errno);
#endif

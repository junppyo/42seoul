/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:13:01 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/10 17:01:35 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_content	*init_con(void)
{
	t_content	*content;

	content = (t_content *) malloc(sizeof(t_content));
	if (!content)
		print_error(MALLOC_ERROR);
	content->collect_cnt = 0;
	content->start_cnt = 0;
	content->exit_cnt = 0;
	return (content);
}

int	get_row(char *s)
{
	int		fd;
	int		row;
	char	*tmp;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		print_error(OPEN_ERROR);
	row = 0;
	tmp = get_next_line(fd);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		row++;
	}
	free(tmp);
	close(fd);
	return (row);
}

char	**make_matrix(char *s, t_content *content)
{
	int		fd;
	char	**ret;
	int		i;
	int		row;

	fd = open(s, O_RDONLY);
	if (fd < 0)
		print_error(OPEN_ERROR);
	row = get_row(s);
	if (row < 0)
		print_error(OPEN_ERROR);
	content->row = row;
	ret = (char **) malloc(sizeof(char *) * row);
	if (!ret)
		print_error(MALLOC_ERROR);
	i = -1;
	while (++i < row)
	{
		ret[i] = get_next_line(fd);
		if (!ret[i])
			print_error(MALLOC_ERROR);
	}
	content->col = ft_strlen(ret[0]) - 1;
	close(fd);
	return (ret);
}

t_player	*init_player(t_game *g)
{
	int			i;
	int			j;
	t_player	*ret;

	ret = (t_player *) malloc(sizeof(t_player));
	ret->pos = (t_point *) malloc(sizeof(t_point));
	i = -1;
	ret->exit_chk = 0;
	while (g->map[++i])
	{
		j = -1;
		while (g->map[i][++j])
		{
			if (g->map[i][j] == 'P')
			{
				ret->pos->x = j;
				ret->pos->y = i;
				return (ret);
			}
		}
	}
	return (0);
}

t_mlx	*init_t_mlx(t_game *g)
{
	int		w;
	int		h;
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr,
			39 * (g->content->col + 1), 44 * g->content->row, "so long");
	w = 40;
	h = 45;
	mlx->img[0] = mlx_png_file_to_image(mlx->mlx_ptr,
			"./image/tile.png", &w, &h);
	mlx->img[1] = mlx_png_file_to_image(mlx->mlx_ptr,
			"./image/wall.png", &w, &h);
	mlx->img[2] = mlx_png_file_to_image(mlx->mlx_ptr,
			"./image/collection.png", &w, &h);
	mlx->img[3] = mlx_png_file_to_image(mlx->mlx_ptr,
			"./image/exit.png", &w, &h);
	mlx->img[4] = mlx_png_file_to_image(mlx->mlx_ptr,
			"./image/character.png", &w, &h);
	return (mlx);
}

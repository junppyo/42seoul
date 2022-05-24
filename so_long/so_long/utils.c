/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:21:27 by junpkim           #+#    #+#             */
/*   Updated: 2022/05/08 21:14:55 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_error(int errno)
{
	ft_printf("Error\n");
	if (errno == OPEN_ERROR)
		ft_printf("OPEN FAIL\n");
	else if (errno == ARG_ERROR)
		ft_printf("NOT ALLOWED FILE TYPE\n");
	else if (errno == MAP_ERROR)
		ft_printf("MAP HAVE DISALLOWED CHARACTER\n");
	else if (errno == ROW_ERROR)
		ft_printf("MAP IS NOT RECTANGLE\n");
	else if (errno == WALL_ERROR)
		ft_printf("NOT ENOUGH WALL\n");
	else if (errno == START_ERROR)
		ft_printf("MAP MUST HAVE ONLY ONE START POINT\n");
	else if (errno == EXIT_ERROR)
		ft_printf("MAP MUST HAVE AT LEAST ONE EXIT\n");
	else if (errno == MALLOC_ERROR)
		ft_printf("MEMORY ALLOCATE FAIL\n");
	else if (errno == COLLECT_ERROR)
		ft_printf("MAP MUST HAVE AT LEAST ONE COLLECTION\n");
	exit(1);
}

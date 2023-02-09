/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_strcts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:44:22 by ibalbako          #+#    #+#             */
/*   Updated: 2023/02/09 11:44:24 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	start_and_ext(t_prm *game)
{
	if (game->map.starting_pos == 'E')
	{
		game->dir_x = 0.0;
		game->dir_y = 1.0;
		game->plane_x = 0.66;
		game->plane_y = 0.0;
	}
	if (game->map.starting_pos == 'W')
	{
		game->dir_x = 0.0;
		game->dir_y = -1.0;
		game->plane_x = -0.66;
		game->plane_y = 0.0;
	}
}

void	ft_init_clr(t_clr *color)
{
	color->red = -1;
	color->elow = -1;
	color->blu = -1;
}

void	ft_init_map(t_map *map)
{
	map->map = NULL;
	map->line = -1;
	map->north_texture = NULL;
	map->south_texture = NULL;
	map->east_texture = NULL;
	map->west_texture = NULL;
	map->filename = NULL;
	map->starting_pos = '\0';
	ft_init_clr(&map->floor_color);
	ft_init_clr(&map->ceilling_color);
	map->player.x = 0;
	map->player.y = 0;
}

void	ft_init_play(t_prm *game)
{
	ft_init_map(&game->map);
	game->mlx = mlx_init();
	game->cub_content = NULL;
	game->screen_h = 1024;
	game->screen_w = 1024;
	game->x = 0;
	ft_new_window(game);
	game->img.prm = mlx_new_image(game->mlx, game->screen_w, game->screen_h);
	game->img.a = (int *)mlx_get_data_addr(game->img.prm, &(game->img.p), \
		&(game->img.len), &(game->img.octet));
}

void	ft_start_all(t_prm *game)
{
	game->r_angle = 0.2;
	game->m_speed = 0.4;
	game->plane_x = 0.0;
	game->plane_y = 0.66;
	game->pos_x = game->map.player.x;
	game->pos_y = game->map.player.y;
	if (game->map.starting_pos == 'N')
	{
		game->dir_x = -1.0;
		game->dir_y = 0.0;
		game->plane_x = 0.0;
		game->plane_y = 0.66;
	}
	if (game->map.starting_pos == 'S')
	{
		game->dir_x = 1.0;
		game->dir_y = 0.0;
		game->plane_x = 0.0;
		game->plane_y = -0.66;
	}
	start_and_ext(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_txtr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:44:57 by sloghmar          #+#    #+#             */
/*   Updated: 2023/02/09 09:44:59 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_mov_bite_rgb(t_clr clr)
{
	return (clr.red << 16 | clr.elow << 8 | clr.blu);
}

void	ft_floor(t_prm *prm)
{
	int	i;

	i = -1;
	while (++i < prm->draw_start)
		prm->img.a[i * prm->screen_w + prm->x] = \
		ft_mov_bite_rgb(prm->map.ceilling_color);
	i = prm->draw_end;
	while (++i < prm->screen_h)
		prm->img.a[i * prm->screen_w + prm->x] = \
		ft_mov_bite_rgb(prm->map.floor_color);
}

void	ft_txtur_wall(t_prm *prm)
{
	if (prm->side == 0)
		prm->wallx = prm->pos_y + prm->perp_wall_dist * \
		prm->raydir_y;
	else
		prm->wallx = prm->pos_x + prm->perp_wall_dist * \
		prm->raydir_x;
	prm->wallx -= (int)((prm->wallx));
	prm->tex_x = (int)(prm->wallx * (double)(prm->tex.w));
	if (prm->side == 0 && prm->raydir_x > 0)
		prm->tex_x = prm->tex.w - prm->tex_x - 1;
	if (prm->side == 1 && prm->raydir_x < 0)
		prm->tex_x = prm->tex.w - prm->tex_x - 1;
	prm->tex_step = 1.0 * prm->tex.h / prm->line_height;
	prm->tex_pos = (prm->draw_start - prm->screen_h \
		/ 2 + prm->line_height / 2) * prm->tex_step;
}

void	g_txtur(t_prm *prm)
{
	if (prm->side == 0 && prm->step_x == -1)
		prm->tex.prm = mlx_xpm_file_to_image(prm->mlx, prm->\
		map.north_texture, &prm->tex.w, &prm->tex.h);
	if (prm->side == 0 && prm->step_x == 1)
		prm->tex.prm = mlx_xpm_file_to_image(prm->mlx, prm->\
		map.south_texture, &prm->tex.w, &prm->tex.h);
	if (prm->side == 1 && prm->step_y == -1)
		prm->tex.prm = mlx_xpm_file_to_image(prm->mlx, prm->\
		map.west_texture, &prm->tex.w, &prm->tex.h);
	if (prm->side == 1 && prm->step_y == 1)
		prm->tex.prm = mlx_xpm_file_to_image(prm->mlx, prm->\
		map.east_texture, &prm->tex.w, &prm->tex.h);
	prm->tex.a = (int *)mlx_get_data_addr(prm->tex.prm, &prm->\
		tex.len, &prm->tex.p, &prm->tex.octet);
}

void	ft_draw_txtr(t_prm *prm)
{
	int		clr;
	int		j;

	j = prm->draw_start;
	while (j < prm->draw_end)
	{
		prm->tex_y = (int)prm->tex_pos & (prm->tex.h - 1);
		prm->tex_pos += prm->tex_step;
		clr = prm->tex.a[prm->tex.h * prm->tex_y \
			+ prm->tex_x];
		if (prm->side == 1)
			clr = (clr >> 1) & 8355711;
		prm->img.a[j * (prm->screen_w) + (prm->x)] = clr;
		j++;
	}
}

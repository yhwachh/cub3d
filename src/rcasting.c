#include "../includes/cub3d.h"

void	ft_position_dis(t_prm *d)
{
	if (!d->perp_wall_dist)
		d->perp_wall_dist = 1;
	d->line_height = (int)(d->screen_h / d->perp_wall_dist);
	d->draw_start = -d->line_height / 2 + d->screen_h / 2;
	if (d->draw_start < 0)
		d->draw_start = 0;
	d->draw_end = d->line_height / 2 + d->screen_h / 2;
	if (d->draw_end >= d->screen_h)
		d->draw_end = d->screen_h - 1;
}

void	ray_draw(t_prm *prm)
{
	if (prm->raydir_x < 0)
	{
		prm->step_x = -1;
		prm->side_dist_x = (prm->pos_x - prm->map_x) \
			* prm->delta_dist_x;
	}
	else
	{
		prm->step_x = 1;
		prm->side_dist_x = (prm->map_x + 1.0 - prm->pos_x) \
			* prm->delta_dist_x;
	}
	if (prm->raydir_y < 0)
	{
		prm->step_y = -1;
		prm->side_dist_y = (prm->pos_y - prm->map_y) \
			* prm->delta_dist_y;
	}
	else
	{
		prm->step_y = 1;
		prm->side_dist_y = (prm->map_y + 1.0 - prm->pos_y) \
			* prm->delta_dist_y;
	}
}

void	r_casting(t_prm *prm)
{
	while (prm->hit == 0)
	{
		if (prm->side_dist_x < prm->side_dist_y)
		{
			prm->side_dist_x += prm->delta_dist_x;
			prm->map_x += prm->step_x;
			prm->side = 0;
		}
		else
		{
			prm->side_dist_y += prm->delta_dist_y;
			prm->map_y += prm->step_y;
			prm->side = 1;
		}
		if (prm->map.map[prm->map_x][prm->map_y] == '1')
			prm->hit = 1;
	}
	if (prm->side == 0)
		prm->perp_wall_dist = fabs((prm->map_x - prm->pos_x + \
		(1 - prm->step_x) / 2) / prm->raydir_x);
	else
		prm->perp_wall_dist = fabs((prm->map_y - prm->pos_y + \
		(1 - prm->step_y) / 2) / prm->raydir_y);
}

void	ft_3d_vue(t_prm *prm)
{
	prm->camera_x = 2 * (prm->x / (double)(prm->screen_w)) - 1;
	prm->raydir_x = prm->dir_x + prm->plane_x \
		* prm->camera_x;
	prm->raydir_y = prm->dir_y + prm->plane_y \
		* prm->camera_x;
	prm->map_x = (int)prm->pos_x;
	prm->map_y = (int)prm->pos_y;
	prm->delta_dist_x = sqrt(1 + pow(prm->raydir_y, 2) \
		/ pow(prm->raydir_x, 2));
	prm->delta_dist_y = sqrt(1 + pow(prm->raydir_x, 2) \
		/ pow(prm->raydir_y, 2));
	prm->hit = 0;
	ray_draw(prm);
}

void	ft_draw(t_prm *parm)
{
	while (parm->x < parm->screen_w)
	{	
		ft_3d_vue(parm);
		r_casting(parm);
		ft_position_dis(parm);
		ft_floor(parm);
		g_txtur(parm);
		ft_txtur_wall(parm);
		ft_draw_txtr(parm);
		parm->x++;
	}
	mlx_put_image_to_window(parm->mlx, parm->win_ptr, parm->img.prm, 0, 0);
}

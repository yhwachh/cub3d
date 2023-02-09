#include "../includes/cub3d.h"

int	ft_key(int key, t_prm *prm)
{
	if (key == 124)
		prm->r_right = 0;
	else if (key == 123)
		prm->r_left = 0;
	else if (key == 13)
		prm->m_up = 0;
	else if (key == 1)
		prm->m_down = 0;
	else if (key == 2)
		prm->m_right = 0;
	else if (key == 0)
		prm->m_left = 0;
	return (0);
}

int	ft_scane(void *prm)
{
	t_prm	*start_prm;

	start_prm = prm;
	mlx_clear_window(start_prm->mlx, start_prm->win_ptr);
	ft_draw(start_prm);
	return (0);
}

void	ft_mov(t_prm *prm)
{
	mlx_destroy_image(prm->mlx, prm->img.prm);
	prm->img.prm = mlx_new_image(prm->mlx, prm->screen_w, \
		prm->screen_h);
	if (prm->r_right == 1)
		ft_rotat(prm, -(prm->r_angle));
	else if (prm->r_left == 1)
		ft_rotat(prm, prm->r_angle);
	else if (prm->m_up == 1)
		ft_forword_map(prm);
	else if (prm->m_down == 1)
		ft_bck_wrd(prm);
	else if (prm->m_right == 1)
		ft_right(prm);
	else if (prm->m_left == 1)
		ft_left(prm);
	mlx_clear_window(prm->mlx, prm->win_ptr);
	prm->x = 0;
	ft_scane(prm);
	mini_map(prm);
}

int	ft_pres_key(int key, t_prm*prm)
{
	if (key == 124)
		prm->r_right = 1;
	else if (key == 123)
		prm->r_left = 1;
	else if (key == 13)
		prm->m_up = 1;
	else if (key == 1)
		prm->m_down = 1;
	else if (key == 2)
		prm->m_right = 1;
	else if (key == 0)
		prm->m_left = 1;
	else if (key == 53)
		ft_close(prm);
	else
		return (1);
	ft_mov(prm);
	return (0);
}

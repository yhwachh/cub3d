#include "../includes/cub3d.h"

void	ft_forword_map(t_prm *ptr)
{
	if (ptr->map.map[(int)(ptr->pos_x + ptr->dir_x)][(int)(\
		ptr->pos_y + ptr->dir_y)] == ZERO)
	{
		ptr->pos_x += ptr->dir_x * ptr->m_speed;
		ptr->pos_y += ptr->dir_y * ptr->m_speed;
	}
}

void	ft_rotat(t_prm *ptr, double angle)
{
	double	olddirx;
	double	oldplanx;

	oldplanx = ptr->plane_x;
	olddirx = ptr->dir_x;
	ptr->dir_x = ptr->dir_x * cos(angle) - \
		ptr->dir_y * sin(angle);
	ptr->dir_y = olddirx * sin(angle) + ptr->dir_y * cos(angle);
	ptr->plane_x = ptr->plane_x * cos(angle) - \
		ptr->plane_y * sin(angle);
	ptr->plane_y = oldplanx * sin(angle) + ptr->plane_y * cos (angle);
}

void	ft_right(t_prm *ptr)
{
	if (ptr->map.map[(int)(ptr->pos_x)][(int)(\
		ptr->pos_y + ptr->dir_y + ptr->plane_y)] == ZERO)
	{
		ptr->pos_y += ptr->plane_y * ptr->m_speed;
		ptr->pos_x += ptr->plane_x * ptr->m_speed;
	}
}

void	ft_bck_wrd(t_prm *ptr)
{
	if (ptr->map.map[(int)(ptr->pos_x - ptr->dir_x)][(int)(\
		ptr->pos_y - ptr->dir_y)] == ZERO)
	{
		ptr->pos_x -= ptr->dir_x * ptr->m_speed;
		ptr->pos_y -= ptr->dir_y * ptr->m_speed;
	}
}

void	ft_left(t_prm *ptr)
{
	if (ptr->map.map[(int)(ptr->pos_x)][(int)(\
		ptr->pos_y + ptr->dir_y - ptr->plane_y)] == ZERO)
	{
		ptr->pos_y -= ptr->plane_y * ptr->m_speed;
		ptr->pos_x -= ptr->plane_x * ptr->m_speed;
	}
}

#include "../includes/cub3d.h"

static void	draw_player(t_prm *map, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < 5)
	{
		i = 0;
		while (i < 5)
		{
			map->img.a[(int)(1 * map->screen_w) * \
				(y + j) + (x + i)] = color;
			i++;
		}
		j++;
	}
}

static void	draw_pixel(t_prm *map, int x, int y, int color)
{
	int	i;
	int	j;

	j = 0;
	while (j < 10)
	{
		i = 0;
		while (i < 10)
		{
			map->img.a[(int)(1 * map->screen_w) * \
				(y + j) + (x + i)] = color;
			i++;
		}
		j++;
	}
}

int	mini_map(t_prm *maps)
{
	int	y;
	int	x;

	y = -1;
	maps->img.a = (int *)mlx_get_data_addr(maps->img.prm, &(maps->img.p), \
		&(maps->img.len), &(maps->img.octet));
	while (maps->map.map[++y])
	{
		x = -1;
		while (maps->map.map[y][++x])
		{
			if (maps->map.map[y][x] == ONE)
				draw_pixel(maps, (int)(10 * x), (int)(10 * y), 0x00929E9C);
			else if (maps->map.map[y][x] == '0' || maps->map.map[y][x] == 'N'
				|| maps->map.map[y][x] == 'E'
					|| maps->map.map[y][x] == 'W'
						|| maps->map.map[y][x] == 'S')
				draw_pixel(maps, (int)(10 * x), (int)(10 * y), 0x00B5A444);
		}
	}
	draw_player(maps, (int)(10 * maps->pos_y), (int)(10 * maps->pos_x), \
		0x00FF00FF);
	mlx_put_image_to_window(maps->mlx, maps->win_ptr, maps->img.prm, 10, 10);
	return (0);
}

#include "../includes/cub3d.h"

void	ft_free(t_prm *game, char *msg)
{
	int	i;

	i = 0;
	while (game->map.map[i])
		free(game->map.map[i++]);
	free(game->map.map);
	free(game->map.filename);
	mlx_destroy_window(game->mlx, game->win_ptr);
	printf("%s\n", msg);
	exit(EXIT_SUCCESS);
}

int	ft_close(t_prm *game)
{
	ft_free(game, "Window Closed");
	return (0);
}

void	ft_new_window(t_prm *game)
{
	game->win_ptr = mlx_new_window(game->mlx, game->screen_w, game->screen_h, \
		"cub3D");
	mlx_hook(game->win_ptr, 17, 0, ft_close, game);
}

int	main(int ac, char *av[])
{
	t_prm	ptr;

	if (ac != 2)
		err_exit("Error! format: ./cub3d [map.cub]\n", 0);
	ft_init_play(&ptr);
	ptr.map.filename = ft_strdup(av[1]);
	map_struct(av[1], &ptr);
	ft_start_all(&ptr);
	ft_scane(&ptr);
	mlx_hook (ptr.win_ptr, 2, 0, &ft_pres_key, &ptr);
	mlx_hook (ptr.win_ptr, 3, 0, &ft_key, &ptr);
	mlx_loop_hook(ptr.mlx, ft_scane, &ptr);
	mlx_loop_hook(ptr.mlx, mini_map, &ptr);
	mlx_loop(ptr.mlx);
	return (0);
}

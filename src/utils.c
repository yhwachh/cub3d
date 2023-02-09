/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:45:00 by ibalbako          #+#    #+#             */
/*   Updated: 2023/02/09 11:45:04 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

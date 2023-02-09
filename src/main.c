/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:46:15 by sloghmar          #+#    #+#             */
/*   Updated: 2023/02/09 09:46:31 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_txtr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibalbako <ibalbako@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 11:44:11 by ibalbako          #+#    #+#             */
/*   Updated: 2023/02/09 11:44:13 by ibalbako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	get_clr(t_clr *clr, char **str)
{
	clr->red = ft_atoi(str[0]);
	clr->elow = ft_atoi(str[1]);
	clr->blu = ft_atoi(str[2]);
}

void	text_open(t_prm *txtr)
{
	if (open(txtr->map.north_texture, O_RDONLY) < 0 \
		|| open(txtr->map.south_texture, O_RDONLY) < 0 \
		|| open(txtr->map.east_texture, O_RDONLY) < 0 \
		|| open(txtr->map.west_texture, O_RDONLY) < 0)
		err_exit("Texture err\n", 1);
}

void	g_textur(t_prm *prm)
{
	char	**texture;
	int		i;

	i = 0;
	while (i < 4)
	{
		texture = ft_split_str(prm->cub_content[i++], ", \n");
		if (!texture)
			return ;
		if (ft_strcmp(texture[0], "NO") == 0)
			prm->map.north_texture = ft_strdup(texture[1]);
		else if (ft_strcmp(texture[0], "SO") == 0)
			prm->map.south_texture = ft_strdup(texture[1]);
		else if (ft_strcmp(texture[0], "WE") == 0)
			prm->map.west_texture = ft_strdup(texture[1]);
		else if (ft_strcmp(texture[0], "EA") == 0)
			prm->map.east_texture = ft_strdup(texture[1]);
		free_split(texture);
	}
	text_open(prm);
}

void	g_posy(t_map *map)
{
	int	f;
	int	l;

	f = 0;
	while (map->map[f])
	{
		l = 0;
		while (map->map[f][l])
		{
			if (test_char(map->map[f][l], "NSEW"))
			{
				map->player.x = f;
				map->player.y = l;
				map->starting_pos = map->map[f][l];
				return ;
			}
			l++;
		}
		f++;
	}
}

void	g_color(t_prm *prm)
{
	char	**get_fc;
	int		i;

	i = 0;
	while (prm->cub_content[i])
	{
		get_fc = ft_split_str(prm->cub_content[i++], ", \n");
		if (!get_fc)
			return ;
		if (ft_strcmp(get_fc[0], "F") == 0)
			get_clr(&prm->map.floor_color, get_fc + 1);
		else if (ft_strcmp(get_fc[0], "C") == 0)
			get_clr(&prm->map.ceilling_color, get_fc + 1);
	}
}

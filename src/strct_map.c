/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strct_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:44:32 by sloghmar          #+#    #+#             */
/*   Updated: 2023/02/09 09:44:36 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	chk_if_closed(char **map, int len)
{
	int	i;
	int	j;

	i = ft_strlen(map[len]);
	j = 0;
	if (map[len + 1])
		j = ft_strlen(map[len + 1]);
	if (i > j && j > 0)
	{
		if (ft_bordur_bis(map, len, j))
			return (1);
	}
	else if (j > i)
	{
		if (ft_bordur_bis(map, len + 1, i))
			return (1);
	}
	return (0);
}

int	ft_chk(char **map, int line, int cln)
{
	if (map[line][cln + 1] == ESPACE || \
		map[line][cln -1] == ESPACE || \
		map[line + 1][cln] == ESPACE || \
		map[line -1][cln] == ESPACE)
		err_exit("Map err\n", 1);
	return (0);
}

int	chk_map_bis(t_prm *map, int line, int cln)
{
	if ((line == 0 && ft_bordur(map->map.map, line, cln)) \
		|| (line == map->map.line - 1 && \
		ft_bordur(map->map.map, line, cln)))
		err_exit("Map err\n", 1);
	else if (cln == 0 && ft_bordur(map->map.map, line, cln))
		err_exit("Map err\n", 1);
	else if (cln == ft_strlen(map->map.map[line]) - 1 && \
		ft_bordur(map->map.map, line, cln))
		err_exit("Map err\n", 1);
	else if ((line > 0 && line < map->map.line - 1) \
			&& (cln > 0 && cln < ft_strlen(map->map.map[line]) - 1))
	{
		if (map->map.map[line][cln] == ZERO && \
			(map->map.map[line + 1][cln] == ESPACE \
			|| map->map.map[line - 1][cln] == ESPACE \
			|| map->map.map[line][cln + 1] == ESPACE \
			|| map->map.map[line][cln - 1] == ESPACE))
			err_exit("Map err\n", 1);
	}
	return (0);
}

int	c_maps(char **map)
{
	int	len;
	int	cln;
	int	find;

	len = 0;
	find = 0;
	while (map[len])
	{
		cln = 0;
		while (map[len][cln] > 0)
		{
			if (!test_char(map[len][cln], " 01NSEW"))
				err_exit("Map err: Character\n", 1);
			if (test_char(map[len][cln], "NSEW") \
			&& !ft_chk(map, len, cln))
				find++;
			cln++;
		}
		len++;
	}
	if (!find)
		err_exit("Map err: Player\n", 1);
	else if (find > 1)
		err_exit("No Multiplayer Game\n", 1);
	return (0);
}

int	c_all_map(t_prm *prm)
{
	int	len;
	int	cln;

	len = 0;
	while (prm->map.map[len])
	{
		cln = 0;
		if (chk_if_closed(prm->map.map, len))
			err_exit("Map err, it don't cls\n", 1);
		while (prm->map.map[len][cln])
		{
			chk_map_bis(prm, len, cln);
			cln++;
		}
		len++;
	}
	return (0);
}

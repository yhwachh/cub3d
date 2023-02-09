/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sloghmar <sloghmar@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:45:13 by sloghmar          #+#    #+#             */
/*   Updated: 2023/02/09 09:45:16 by sloghmar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ck_generet_line(char *str)
{
	return (str[ft_strlen(str) - 1] == '\n');
}

void	g_map(t_prm *par)
{
	int	i;
	int	f;

	i = 0;
	f = 0;
	par->map.line = map_len(par);
	par->map.map = malloc(sizeof(char *) * (par->map.line + 1));
	par->map.colonne = 0;
	if (!par->map.map)
		err_exit("Malloc err\n", 1);
	while (par->cub_content[i])
	{
		if (par->cub_content[i][0] == ONE
			|| par->cub_content[i][0] == ESPACE
			|| par->cub_content[i][0] == ZERO)
		{
			par->map.map[f++] = ft_strndup(par->cub_content[i],
					ft_strlen(par->cub_content[i]) - \
					ck_generet_line(par->cub_content[i]));
			if (par->map.colonne < ft_strlen(par->map.map[f - 1]))
				par->map.colonne = ft_strlen(par->map.map[f - 1]);
		}
		i++;
	}
	par->map.map[f] = NULL;
}

void	data(t_prm *par)
{
	int	len;
	int	i;
	int	file;

	i = 0;
	len = nb_ligne_map(par->map.filename);
	par->cub_content = malloc(sizeof(char *) * (len + 1));
	if (!par->cub_content)
		err_exit("Malloc err\n", 1);
	file = open(par->map.filename, O_RDONLY);
	if (file == -1)
		err_exit("File err\n", 1);
	par->cub_content[i] = get_next_line(file);
	while (i < len && par->cub_content[i++])
		par->cub_content[i] = get_next_line(file);
	par->cub_content[i] = 0;
	close(file);
}

void	map_struct(char *av, t_prm *par)
{
	par->map.filename = ft_strdup(av);
	data(par);
	map_chek(par);
	g_textur(par);
	g_color(par);
	g_map(par);
	g_posy(&par->map);
	c_maps(par->map.map);
	c_all_map(par);
}

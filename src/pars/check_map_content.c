#include "../../includes/cub3d.h"

int	ft_bordur(char **map, int len, int cln)
{
	if (map[len][cln] != ONE && map[len][cln] != ESPACE)
		return (1);
	return (0);
}

int	ft_bordur_bis(char **map, int len, int index)
{
	while (map[len][index])
	{
		if (map[len][index] != ONE && map[len][index] != ESPACE)
			return (1);
		index++;
	}
	return (0);
}

void	chk_map_prm(t_parma *prm, int *i)
{
	int		f;

	f = 0;
	while (*i < 4 && prm->cub_content[*i])
	{
		if (ft_strncmp(prm->cub_content[*i], "NO ", 3) == 0 \
			|| ft_strncmp(prm->cub_content[*i], "SO ", 3) == 0 \
			|| ft_strncmp(prm->cub_content[*i], "WE ", 3) == 0 \
			|| ft_strncmp(prm->cub_content[*i], "EA ", 3) == 0 \
			)
		{		
			f++;
		}
		(*i)++;
	}
	if (*i != f && f != 4)
		err_exit("textur err\n", 1);
	if (*i == 0)
		err_exit("file err: Empty Texture", 1);
}

void	chk_map_clr(char **clr, int *i)
{
	int		f;
	int		d;
	int		k;

	f = 0;
	k = *i;
	d = *i + 2;
	while (*i < d && clr[*i])
	{
		if (ft_strncmp(clr[*i], "F ", 2) == 0 \
			|| ft_strncmp(clr[*i], "C ", 2) == 0)
			f++;
		(*i)++;
	}
	if (*i - k != f)
		err_exit("clr err\n", 1);
}

void	map_chek(t_parma *prm)
{
	int	i;

	i = 0;
	chk_map_prm(prm, &i);
	while (prm->cub_content[i] && ft_strcmp(prm->cub_content[i], "\n") == 0)
		i++;
	chk_map_clr(prm->cub_content, &i);
	while (prm->cub_content[i] && ft_strcmp(prm->cub_content[i], "\n") == 0)
		i++;
}

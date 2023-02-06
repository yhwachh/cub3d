#include "../../includes/cub3d.h"

void	err_exit(char *msg, int code)
{
	ft_putstr_fd(msg, code);
	exit(code);
}

void	free_all(t_map *parma)
{
	int	i;

	i = -1;
	while (parma->map[++i])
	{
		free(parma->map[i]);
	}
	free(parma->map);
}

void	free_split(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

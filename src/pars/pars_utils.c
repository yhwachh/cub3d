#include "../../includes/cub3d.h"

void	err_exit(char *file, int cod)
{
	ft_putstr_fd(file, cod);
	exit(cod);
}

void	free_split(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

int	test_char(char str1, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str1 == str[i])
			return (1);
		i++;
	}
	return (0);
}

int	nb_ligne_map(char *th)
{
	int		i;
	int		fd;
	char	*ligne;

	i = 0;
	fd = open(th, O_RDONLY);
	if (fd == -1)
		err_exit("File err\n", 1);
	ligne = get_next_line(fd);
	while (ligne)
	{
		free(ligne);
		i++;
		ligne = get_next_line(fd);
	}
	close(fd);
	return (i);
}

int	map_len(t_parma *prm)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (prm->cub_content[i])
	{
		if (prm->cub_content[i][0] == ONE
			|| prm->cub_content[i][0] == ZERO
			|| prm->cub_content[i][0] == ESPACE)
			len++;
		i++;
	}
	return (len);
}

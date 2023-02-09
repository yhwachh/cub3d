
#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <fcntl.h>
# include <math.h> 
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "structs.h" 
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define ESPACE 32
# define ONE 49
# define ZERO 48

void	ft_init_play(t_prm *game);
void	ft_start_all(t_prm *game);
void	cub_3d(t_prm *ptr_mlx, t_map *prm);
int		mini_map(t_prm *maps);
void	err_exit(char *msg, int code);
void	free_split(char **tab);
void	data(t_prm *prm);
void	map_struct(char *argv, t_prm *prm);
void	g_map(t_prm *prm);
void	find_player(t_prm *prm);
int		test_char(char car, char *str);
int		nb_ligne_map(char *path);
int		map_len(t_prm *prm);
int		c_maps(char **map);
int		c_all_map(t_prm *prm);
int		ft_bordur(char **map, int ligne, int index);
int		ft_bordur_bis(char **map, int ligne, int index);
int		chk_if_closed(char **map, int ligne);
void	map_chek(t_prm *prm);
int		ck_generet_line(char *str);
void	ray_draw(t_prm *wall);
void	ft_floor(t_prm *star);
void	g_txtur(t_prm *parm);
void	ft_txtur_wall(t_prm *parm);
void	ft_draw_txtr(t_prm *parm);
void	ft_draw(t_prm *parm);
int		ft_key(int key, t_prm *ptr);
int		ft_pres_key(int key, t_prm*ptr);
void	ft_rotat(t_prm *ptr, double angle);
void	ft_left(t_prm *ptr);
void	ft_right(t_prm *ptr);
void	ft_bck_wrd(t_prm *ptr);
void	ft_forword_map(t_prm *ptr);
int		ft_scane(void *ptr);
void	ft_new_window(t_prm *game);
int		ft_close(t_prm *game);
void	ray_draw(t_prm *wall);
void	ft_floor(t_prm *star);
void	g_txtur(t_prm *parm);
void	ft_txtur_wall(t_prm *parm);
void	ft_draw_txtr(t_prm *parm);
void	ft_draw(t_prm *parm);
void	g_textur(t_prm *prm);
void	g_color(t_prm *prm);
void	g_posy(t_map *map);

#endif

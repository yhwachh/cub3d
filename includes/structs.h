
#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_pic
{
	void	*prm;
	int		len;
	int		p;
	int		octet;
	int		*a;
	int		w;
	int		h;
}	t_pic;

typedef struct s_vct
{
	int	x;
	int	y;
}	t_vct;

typedef struct s_clr
{
	int	red;
	int	elow;
	int	blu;
}	t_clr;

typedef struct s_map
{
	char		**map;
	int			line;
	int			colonne;
	char		*north_texture;
	char		*south_texture;
	char		*west_texture;
	char		*east_texture;
	char		*filename;
	char		starting_pos;
	t_clr		floor_color;
	t_clr		ceilling_color;
	t_vct		player;
}	t_map;

typedef struct s_prm
{
	void		*mlx;
	void		*win_ptr;
	char		**cub_content;
	t_map		map;
	t_pic		img;
	t_pic		tex;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		raydir_x;
	double		raydir_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_dist_x;
	double		side_dist_y;
	double		perp_wall_dist;
	double		m_speed;
	double		r_angle;
	double		wallx;
	double		tex_pos;
	double		tex_step;
	int			r_right;
	int			m_right;
	int			r_left;
	int			m_left;
	int			m_up;
	int			m_down;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			map_x;
	int			map_y;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			x;
	int			tex_x;
	int			tex_y;
	int			screen_w;
	int			screen_h;
}				t_prm;

#endif

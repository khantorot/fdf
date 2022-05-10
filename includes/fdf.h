/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 11:07:33 by glychest          #+#    #+#             */
/*   Updated: 2020/02/02 17:37:28 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "math.h"
# include "mlx.h"
# include "libft.h"

# define HEIGHT				1440
# define WIDTH				2560

# define BACKGROUND			0x000000
# define COLOR_1			0x92123b
# define COLOR_2			0xc27272
# define COLOR_3			0x119091
# define COLOR_4			0x119134
# define COLOR_5			0x431191

# define KEY_W				13
# define KEY_D				2
# define KEY_S				1
# define KEY_A				0
# define KEY_Q				12
# define KEY_E				14
# define KEY_I				34
# define KEY_P				35
# define KEY_ESC			53
# define KEY_PLUS			69
# define KEY_MINUS			78
# define KEY_LESS			43
# define KEY_MORE			47
# define KEY_UP				126
# define KEY_DOWN			125
# define KEY_LEFT			123
# define KEY_RIGHT			124

typedef struct			s_map
{
	int					width;
	int					height;
	int					*position;
	int					*colors;
	int					z_max;
	int					z_min;
	int					range;
}						t_map;

typedef struct			s_val
{
	int					z;
	int					color;
	struct s_val		*next;
}						t_val;

typedef struct			s_dot
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_dot;

typedef struct			s_camera
{
	t_bool				projection;
	int					zoom;
	double				alpha;
	double				beta;
	double				gamma;
	float				z_divisor;
	int					x_offset;
	int					y_offset;
}						t_camera;

typedef struct			s_data
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data_addr;
	int					bits_per_pixel;
	int					line_size;
	int					endian;
	t_camera			*camera;
	t_map				*map;
}						t_data;

t_map					*init_map(void);
int						read_map(int fd, t_val **val, t_map *map);
t_data					*data_init(t_map *map);
void					fill_map(t_val **val, t_map *map);
t_val					*pop(t_val **val);
t_camera				*camera_init(t_data *data);
void					draw(t_map *map, t_data *data);
t_dot					project(t_dot dot, t_data *data);
int						get_color(t_dot current, t_dot start,
									t_dot end, t_dot delta);
int						get_default_color(int z, t_map *map);
void					setup_controls(t_data *data);
int						key_press(int key, void *param);
void					rotate_x(int *y, int *z, double alpha);
void					rotate_y(int *x, int *z, double beta);
void					rotate_z(int *x, int *y, double gamma);
void					zoom(int key, t_data *data);
void					move(int key, t_data *data);
void					rotate(int key, t_data *data);
void					align(int key, t_data *data);
void					iso(int *x, int *y, int z);
void					change_projection(int key, t_data *data);
int						close_fdf(void *param);

#endif

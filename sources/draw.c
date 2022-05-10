/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 13:06:54 by glychest          #+#    #+#             */
/*   Updated: 2020/01/30 18:07:37 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void			plot(t_data *data, int x, int y, int color)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * data->bits_per_pixel / 8) + (y * data->line_size);
		data->data_addr[i] = color;
		data->data_addr[++i] = color >> 8;
		data->data_addr[++i] = color >> 16;
	}
}

static void			draw_line(t_dot f, t_dot s, t_data *data)
{
	t_dot	delta;
	t_dot	sign;
	t_dot	cur;
	int		error[2];

	delta.x = ft_abs(s.x - f.x);
	delta.y = ft_abs(s.y - f.y);
	sign.x = f.x < s.x ? 1 : -1;
	sign.y = f.y < s.y ? 1 : -1;
	error[0] = delta.x - delta.y;
	cur = f;
	while (cur.x != s.x || cur.y != s.y)
	{
		plot(data, cur.x, cur.y, get_color(cur, f, s, delta));
		if ((error[1] = error[0] * 2) > -delta.y)
		{
			error[0] -= delta.y;
			cur.x += sign.x;
		}
		if (error[1] < delta.x)
		{
			error[0] += delta.x;
			cur.y += sign.y;
		}
	}
}

static void			clear_background(t_data *data)
{
	int	*image;
	int	i;

	ft_bzero(data->data_addr, WIDTH * HEIGHT * (data->bits_per_pixel / 8));
	image = (int *)(data->data_addr);
	i = 0;
	while (i < HEIGHT * WIDTH)
	{
		image[i] = BACKGROUND;
		i++;
	}
}

static t_dot		get_dot(int x, int y, t_map *map)
{
	t_dot	dot;
	int		index;

	index = y * map->width + x;
	dot.x = x;
	dot.y = y;
	dot.z = map->position[index];
	dot.color = (map->colors[index] == -1) ?
			get_default_color(dot.z, map) : map->colors[index];
	return (dot);
}

void				draw(t_map *map, t_data *data)
{
	int		x;
	int		y;

	clear_background(data);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != data->map->width - 1)
				draw_line(project(get_dot(x, y, map), data),
					project(get_dot(x + 1, y, map), data), data);
			if (y != data->map->height - 1)
				draw_line(project(get_dot(x, y, map), data),
					project(get_dot(x, y + 1, map), data), data);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

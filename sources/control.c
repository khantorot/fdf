/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/05 13:17:34 by glychest          #+#    #+#             */
/*   Updated: 2020/01/30 17:20:37 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			key_press(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_PLUS || key == KEY_MINUS)
		zoom(key, data);
	else if (key == KEY_LEFT || key == KEY_RIGHT
		|| key == KEY_UP || key == KEY_DOWN)
		move(key, data);
	else if (key == KEY_Q || key == KEY_W || key == KEY_E
		|| key == KEY_A || key == KEY_S || key == KEY_D)
		rotate(key, data);
	else if (key == KEY_LESS || key == KEY_MORE)
		align(key, data);
	else if (key == KEY_P || key == KEY_I)
		change_projection(key, data);
	return (0);
}

void		zoom(int key, t_data *data)
{
	if (key == KEY_PLUS)
		data->camera->zoom++;
	else if (key == KEY_MINUS)
		data->camera->zoom--;
	if (data->camera->zoom < 1)
		data->camera->zoom = 1;
	draw(data->map, data);
}

void		move(int key, t_data *data)
{
	if (key == KEY_LEFT)
		data->camera->x_offset -= 7;
	else if (key == KEY_RIGHT)
		data->camera->x_offset += 7;
	else if (key == KEY_UP)
		data->camera->y_offset -= 7;
	else
		data->camera->y_offset += 7;
	draw(data->map, data);
}

void		rotate(int key, t_data *data)
{
	if (key == KEY_S)
		data->camera->alpha += 0.03;
	else if (key == KEY_W)
		data->camera->alpha -= 0.03;
	else if (key == KEY_A)
		data->camera->beta -= 0.03;
	else if (key == KEY_D)
		data->camera->beta += 0.03;
	else if (key == KEY_E)
		data->camera->gamma += 0.03;
	else if (key == KEY_Q)
		data->camera->gamma -= 0.03;
	draw(data->map, data);
}

void		align(int key, t_data *data)
{
	if (key == KEY_LESS)
		data->camera->z_divisor += 0.1;
	else if (key == KEY_MORE)
		data->camera->z_divisor -= 0.1;
	if (data->camera->z_divisor < 0.1)
		data->camera->z_divisor = 0.1;
	else if (data->camera->z_divisor > 10)
		data->camera->z_divisor = 10;
	draw(data->map, data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glychest <glychest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 17:48:56 by glychest          #+#    #+#             */
/*   Updated: 2020/01/30 18:07:54 by glychest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	change_projection(int key, t_data *data)
{
	data->camera->alpha = 0;
	data->camera->beta = 0;
	data->camera->gamma = 0;
	if (key == KEY_I)
		data->camera->projection = false;
	else if (key == KEY_P)
		data->camera->projection = true;
	draw(data->map, data);
}

int		close_fdf(void *param)
{
	(void)param;
	exit(0);
}

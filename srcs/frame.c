/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:23:46 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/25 20:38:17 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			mlx_pixel(int x, int y, t_rt *e, int color)
{
	int			pos;

	if (x < LARGEUR && y < HAUTEUR)
	{
		pos = x * 4 + y * e->mlx.size_l;
		e->mlx.data[pos] = color;
		e->mlx.data[pos + 1] = color >> 8;
		e->mlx.data[pos + 2] = color >> 16;
	}
}

void			pixel_to_image(int x, int y, t_rt *e, int color)
{
	int			max_x;
	int			max_y;
	int			start_y;

	x = x * RES;
	y = y * RES;
	start_y = y;
	max_x = x + RES;
	max_y = y + RES;
	while (x <= max_x)
	{
		while (y <= max_y)
		{
			if ((x >= 0 && y >= 0) || (x < RES_W && y < RES_H))
				mlx_pixel(x, y, e, color);
			y++;
		}
		y = start_y;
		x++;
	}
}

void			*drawline(void *arg)
{
	t_rt		*e;
	int			y;
	int			x;
	int			i;

	e = (t_rt *)arg;
	if (!(e->thread.colors =
	malloc((e->thread.h * e->thread.w + 1) * sizeof(t_color))))
		exit(42);
	y = e->thread.y;
	i = 0;
	while (y < e->thread.max_y)
	{
		x = 0;
		while (x < e->thread.w)
		{
			e->thread.colors[i] = raytrace(x, y, e);
			++x;
			++i;
		}
		++y;
	}
	return (NULL);
}

void			frame(t_rt *e)
{
	t_rt		**th_e;
	int			i;
	int			i2;
	int			ny;
	int			nx;

	e->frame++;
	th_e = launch_thread(e);
	i = -1;
	while (++i < NB_THREADS &&
		(ny = (th_e[i]->thread.y / e->file.aliasing) - 1) != -42424242 &&
		(i2 = -1) == -1)
		while (++ny < th_e[i]->thread.max_y / e->file.aliasing &&
			(nx = -1) == -1)
			while (++nx < th_e[i]->thread.w / e->file.aliasing)
				pixel_to_image(nx, ny, e,
					ret_colors(th_e[i]->thread.colors[++i2]));
	i = 0;
	while (i < NB_THREADS)
	{
		free(th_e[i]->thread.colors);
		free(th_e[i++]);
	}
	free(th_e);
	mlx_put_image_to_window(INIT, WIN, IMG, 0, 0);
}

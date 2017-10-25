/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_begin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 23:41:56 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/25 20:41:01 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			ft_start_rt(t_rt *e)
{
	e->mlx.window = mlx_new_window(
		e->mlx.init,
		e->file.larg,
		e->file.haut,
		"RTV1");
	e->mlx.image = mlx_new_image(e->mlx.init, e->file.larg, e->file.haut);
	e->mlx.data = mlx_get_data_addr(e->mlx.image, &e->mlx.bpp,
		&e->mlx.size_l, &e->mlx.endian);
	frame(e);
	mlx_put_image_to_window(INIT, WIN, IMG, 0, 0);
	mlx_hook(e->mlx.window, 2, 0, keypress, e);
	mlx_hook(e->mlx.window, 17, 0, (int (*)())exit, NULL);
	mlx_loop(e->mlx.init);
}

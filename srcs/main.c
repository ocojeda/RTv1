/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 23:41:30 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/24 21:53:59 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		main(int argc, char **argv)
{
	t_rt	e;

	e.mlx.init = mlx_init();
	e.scene.nbr_light = 0;
	e.scene.nbr_obj = 0;
	e.frame = 0;
	parse(&e, argc, argv);
	ft_start_rt(&e);
	return 0;
}

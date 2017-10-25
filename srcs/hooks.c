/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:18:30 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/25 20:39:08 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int				keypress(int keycode, void *param)
{
	t_rt	*e;

	e = (t_rt *)param;
	if (keycode == KEY_ESC)
		exit(42);
	return (keycode);
}

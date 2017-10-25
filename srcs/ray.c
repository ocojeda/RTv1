/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:43:14 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/25 20:44:56 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray			c_ray(t_vec3 i, t_vec3 j)
{
	t_ray		ray;

	ray.pos = vec_new3(i.x, i.y, i.z);
	ray.dir = vec_norme3(vec_new3(j.x, j.y, j.z));
	return (ray);
}

t_ray			ray_init(t_rt *e, int x, int y)
{
	t_ray	ray;

	ray.pos = e->scene.cam.pos;
	if (e->scene.cam.focus_point.z < 0)
		ray.dir =
	vec_norme3(vec_sub3(vec_sub3(e->scene.cam.focus_point,
	vec_new3(x, y, e->scene.cam.focus_point.z + 1)), e->scene.cam.pos));
	else
		ray.dir =
	vec_norme3(vec_sub3(vec_sub3(e->scene.cam.focus_point,
	vec_new3(x, y, e->scene.cam.focus_point.z - 1)), e->scene.cam.pos));
	return (ray);
}

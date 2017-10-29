/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:43:14 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/29 17:16:12 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_ray			get_reflected_ray(t_rt *e, t_ray rayon, t_vec3 poi)
{
	t_vec3		normale;
	t_ray		ray;

	ray.pos = poi;
	normale = color_norm(e->scene.obj[e->scene.id], poi, e->scene.cam.pos);
	ray.dir = vec_add3(vec_scale3(normale,
		(-2 * vec_dot3(rayon.dir, normale))), rayon.dir);
	return (ray);
}

float			get_length(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

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

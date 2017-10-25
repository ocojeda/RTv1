/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:41:36 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/25 20:41:47 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec3			plane_norm(t_obj plane)
{
	return (plane.vector);
}

float			intersect_plane(t_ray ray, t_obj *plane)
{
	float		d;
	float		dist;
	t_vec3		vector_distance;

	if ((d = vec_dot3(plane->vector, ray.dir)) == 0)
		return (DIST_MAX);
	vector_distance = vec_sub3(plane->pos, ray.pos);
	dist = vec_dot3(vector_distance, plane->vector) / d;
	if (dist <= 0)
		return (DIST_MAX);
	return (dist);
}

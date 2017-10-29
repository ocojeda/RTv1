/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intensity.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:39:37 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/25 20:47:10 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

float			get_length(t_vec3 v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

float			obj_isnt_in_shadow(t_rt *e, t_vec3 poi, t_light *light)
{
	t_ray	ray;
	float	dist;
	float	dist_to_light;
	float	opac;
	int		i;

	i = -1;
	opac = 1;
	light->ray.dir = vec_sub3(light->ray.pos, poi);
	dist_to_light = get_length(light->ray.dir);
	light->ray.dir = vec_norme3(light->ray.dir);
	ray = c_ray(vec_add3(poi, light->ray.dir), light->ray.dir);
	while (++i < e->scene.nbr_obj)
	{
		dist = intersect_obj(ray, &e->scene.obj[i]);
		if (dist > 0 && dist < dist_to_light)
			opac = 0;
	}
	return (opac);
}

float		diff_intensity(t_obj obj, float dot, t_light light)
{
	float	intensity;

	if (obj.mat.diff == 0)
		return (0);
	intensity = light.intensity;
	intensity *= dot;
	return ((intensity < 0) ? 0 : intensity);
}

float		spec_intensity(t_obj obj, t_ray light, t_vec3 norm, float dot)
{
	float	intensity;
	t_vec3	refl;

	(void)obj;
	//if (obj.mat.spec == 0)
	//	return (0);
	refl = vec_sub3(light.dir, vec_inv3(vec_scale3(norm, dot)));
	intensity = vec_dot3(light.dir, refl) * obj.mat.diff;
	//while(intensity > 1)
	//	intensity/=2;
	intensity = ft_map(intensity, 2, 0, 1);
//	intensity = ft_map(intensity, 2, 0, 0.1);
	return intensity;
}

float		intensity_obj(t_rt *e, t_vec3 poi, t_obj obj, t_light light)
{
	float	intensity;
	t_vec3	norm;
	float	transp;
	float	dot;

	intensity = 0;
	transp = 0;
	light.ray.dir = vec_norme3(vec_sub3(light.ray.pos, poi));
	norm = color_norm(obj, poi, vec_sub3(e->scene.cam.pos, poi));
	if ((dot = vec_dot3(light.ray.dir, norm)) > 0
		&& (transp = obj_isnt_in_shadow(e, poi, &light)))
	{
		intensity = diff_intensity(obj, dot, light);
		intensity += spec_intensity(obj, light.ray, norm, dot);
	//	
	//intensity += pow(intensity, spec_intensity(obj, light.ray, norm, dot));
	}
	return (intensity * transp + AMBIENT_LIGHT);
}
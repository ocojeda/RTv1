/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 23:57:38 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/24 00:24:55 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		parse_camera(t_rt *e, xmlNodePtr node)
{
	xmlNodePtr	child;

	if ((child = has_child(node, "pos")))
		e->scene.cam.pos = get_vec_from_node(child);
	if ((child = has_child(node, "dir")))
		e->scene.cam.focus_point = get_vec_from_node(child);
}

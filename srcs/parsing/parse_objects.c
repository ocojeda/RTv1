/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:37:02 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/23 22:23:35 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static void		set_attrs(t_obj *obj, xmlNodePtr node)
{
	xmlChar		*val;

	if ((val = xmlGetProp(node, BAD_CAST"radius")))
		obj->r = ft_atof((char *)val);
	if ((val = xmlGetProp(node, BAD_CAST"shine")))
		obj->mat.diff = ft_atof((char *)val);
	if ((val = xmlGetProp(node, BAD_CAST"angle")))
		obj->k = ft_atof((char *)val);
}

static void		parse_obj_node(t_obj *obj, xmlNodePtr node, t_rt *e)
{
	xmlNodePtr	child;

	set_attrs(obj, node);
	if ((child = has_child(node, "pos")))
		obj->pos = get_vec_from_node(child);
	if ((child = has_child(node, "normal")))
		obj->vector = vec_norme3(get_vec_from_node(child));
	if ((child = has_child(node, "color")))
		obj->color = parse_color(child);
}

static t_obj	dispatch_obj(xmlNodePtr node, t_rt *e, int i)
{
	t_obj 		new_obj;

	if (xmlStrEqual(node->name, (xmlChar *)"sphere"))
		new_obj.type = SPHERE;
	else if (xmlStrEqual(node->name, (xmlChar *)"plane"))
		new_obj.type = PLANE;
	else if (xmlStrEqual(node->name, (xmlChar *)"cone"))
		new_obj.type = CONE;
	else if (xmlStrEqual(node->name, (xmlChar *)"cylinder"))
		new_obj.type = CYLINDER;
	parse_obj_node(&new_obj, node, e);
	return (new_obj);
}

static void		create_obj(t_rt *e, t_list *lst)
{
	int i;

	i = 0;
	e->scene.nbr_obj = ft_lstlen(lst);
	if (e->scene.nbr_obj == 0)
		return ;
	while (lst)
	{
		e->scene.obj[i] = dispatch_obj((xmlNodePtr)lst->content, e, i);
		lst = lst->next;
		i++;
	}
	ft_lstfree(&lst);
}

void			parse_objects(t_rt *e, xmlNodePtr node)
{
	t_list		*lst;
	t_list		*lst2;
	t_list		*new;
	xmlNodePtr	temp;

	lst = NULL;
	lst2 = NULL;
	temp = NULL;
	get_nodes_by_name(node, "objects", &lst);
	if (!lst)
		return ;
	temp = ((xmlNodePtr)lst->content)->children;
	while (temp)
	{
		ft_putendl((char *)temp->name);
		new = ft_lstnew((void *)temp, sizeof(*temp));
		ft_lstpush(&lst2, new);
		temp = temp->next;
	}
	create_obj(e, lst2);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:25:44 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/24 00:25:54 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

xmlNodePtr		has_child(xmlNodePtr a_node, char *attr)
{
	xmlChar		*cast;
	xmlNodePtr	cur;

	cur = NULL;
	cur = a_node->children;
	cast = (xmlChar *)attr;
	while (cur)
	{
		if (!xmlStrcmp(cur->name, cast))
			return (cur);
		cur = cur->next;
	}
	return (NULL);
}

t_color			parse_color(xmlNodePtr node)
{
	t_color color;

	color = c_color(
		ft_atoi((char *)xmlGetProp(node, (xmlChar *)"r")),
		ft_atoi((char *)xmlGetProp(node, (xmlChar *)"g")),
		ft_atoi((char *)xmlGetProp(node, (xmlChar *)"b")));
	return (color);
}

t_vec3			get_vec_from_node(xmlNodePtr node)
{
	t_vec3	new_vec;

	new_vec.x = ft_atof((char *)(xmlGetProp(node, (xmlChar *)"x")));
	new_vec.y = ft_atof((char *)(xmlGetProp(node, (xmlChar *)"y")));
	new_vec.z = ft_atof((char *)(xmlGetProp(node, (xmlChar *)"z")));
	return (new_vec);
}

void			get_nodes_by_name(xmlNodePtr cur, char *node_name, t_list **lst)
{
	t_list	*new_lst;

	while (cur)
	{
		if ((xmlStrEqual(cur->name, (xmlChar *)node_name)))
		{
			new_lst = ft_lstnew((void *)cur, sizeof(*cur));
			ft_lstpush(lst, new_lst);
		}
		get_nodes_by_name(cur->children, node_name, lst);
		cur = cur->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:40:51 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/22 19:36:53 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

static int		calcul_res(t_rt *e, int limit)
{
	int res;
	int air;

	air = e->file.larg * e->file.haut;
    res = 1;
    limit /= 2;
	while ((air / res) > limit)
		res++;
	return (res);
}

static void		parse_scene(t_rt *e, xmlNodePtr node)
{
	xmlChar	*val;

	val = xmlGetProp(node, (xmlChar*)"ambient");
	e->scene.ambient = ft_atof((char*)val);
	e->scene.ambient = (e->scene.ambient > 1) ? 1.00 : e->scene.ambient;
	e->scene.ambient = (e->scene.ambient < 0) ? 0 : e->scene.ambient;
	xmlFree(val);
	val = xmlGetProp(node, (xmlChar*)"width");
	e->file.larg = ft_atoi((char*)val);
	xmlFree(val);
	val = xmlGetProp(node, (xmlChar*)"height");
	e->file.haut = ft_atoi((char*)val);
    e->file.aliasing = 1;
    e->file.reso = calcul_res(e, 400000);
	e->file.reso_buff = e->file.reso;
	xmlFree(val);
}

void			parse(t_rt *e, int ac, char **av)
{
	xmlDocPtr	doc;
	xmlNodePtr	root;

	// debug
	//if (ac != 2 || ft_strncmp(ft_strrev(av[1]), "lmx.", 4) != 0)
	//	err_found("usage: rtv1 input_map.xml");
	// doc = xmlParseFile(ft_strrev(av[1]));
	doc = xmlParseFile("scenes/01.xml"); // debug
	if (doc == NULL)
		err_found("Wrong xml file");
	check_doc(doc);
	root = xmlDocGetRootElement(doc);
	parse_scene(e, root);
	parse_objects(e, root);
	xmlFreeDoc(doc);
	xmlCleanupParser();
}
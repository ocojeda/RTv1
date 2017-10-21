/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:40:51 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/21 18:24:49 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	parse(t_rt *e, int ac, char **av)
{
	xmlDocPtr	doc;
	xmlNodePtr	root;

	if (ac != 2 || ft_strncmp(ft_strrev(av[1]), "lmx.", 4) != 0)
		err_found("usage: rtv1 input_map.xml");
	doc = xmlReadFile(ft_strrev(av[1]), NULL, 0);
	if (doc == NULL)
		err_found("Wrong xml file");
	root = xmlDocGetRootElement(doc);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:25:44 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/22 19:35:39 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		get_nodes_by_name(xmlNodePtr cur, char *node_name, t_list **lst)
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

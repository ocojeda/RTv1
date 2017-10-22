/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 19:37:02 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/22 19:44:51 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		parse_objects(t_rt *e, xmlNodePtr node)
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
	return ;
}
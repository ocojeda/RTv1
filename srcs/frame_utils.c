/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 20:32:11 by bbeldame          #+#    #+#             */
/*   Updated: 2017/10/25 20:33:32 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_rt			*copy_rt(t_rt *e)
{
	t_rt		*copy;

	copy = NULL;
	if ((copy = (t_rt *)malloc(sizeof(t_rt))) == NULL)
		exit(42);
	copy->scene = e->scene;
	copy->file.larg = e->file.larg;
	copy->file.haut = e->file.haut;
	copy->file.reso = e->file.reso;
	copy->file.aliasing = e->file.aliasing;
	return (copy);
}

t_rt			**launch_thread(t_rt *e)
{
	int			i;
	pthread_t	th[NB_THREADS];
	t_rt		**th_e;

	if (!(th_e = (t_rt **)malloc(NB_THREADS * sizeof(t_rt *))))
		return (NULL);
	i = -1;
	while (++i < NB_THREADS)
	{
		th_e[i] = copy_rt(e);
		THREAD.h = HAUTEUR * e->file.aliasing;
		THREAD.w = LARGEUR * e->file.aliasing;
		THREAD.h /= RES;
		THREAD.w /= RES;
		THREAD.y = ((THREAD.h) / NB_THREADS) * i;
		THREAD.max_y = THREAD.y + ((THREAD.h) / NB_THREADS);
		pthread_create(&th[i], NULL, drawline, (void *)th_e[i]);
	}
	i = -1;
	while (++i < NB_THREADS)
		pthread_join(th[i], NULL);
	return (th_e);
}

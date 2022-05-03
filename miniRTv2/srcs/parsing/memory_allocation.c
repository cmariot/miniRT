/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:01:44 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 09:19:39 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	memory_allocation(t_world *world,
	t_obj_list *obj_list, t_light_list *light_list)
{
	if (obj_list->nb_objs)
	{
		obj_list->objs
			= (t_obj *)malloc(sizeof(t_obj) * obj_list->nb_objs);
		if (!obj_list->objs)
			return (rt_error("Memory allocation failed."));
	}
	if (obj_list->nb_camera)
	{
		world->camera
			= malloc(sizeof(t_cam) * obj_list->nb_camera);
		if (!world->camera)
			return (rt_error("Memory allocation failed."));
	}
	if (obj_list->nb_spot_light)
	{
		light_list->spot_light
			= malloc(sizeof(t_light) * obj_list->nb_spot_light);
		if (!light_list->spot_light)
			return (rt_error("Memory allocation failed."));
	}
	return (0);
}

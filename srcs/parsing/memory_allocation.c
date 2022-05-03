/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:01:44 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 23:43:42 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	memory_allocation(t_obj_list *obj_list)
{
	if (obj_list->nb_objs)
	{
		obj_list->objs = malloc(sizeof(t_obj) * obj_list->nb_objs);
		if (!obj_list->objs)
			return (rt_error("Memory allocation failed."));
	}
	if (obj_list->nb_camera)
	{
		obj_list->camera = malloc(sizeof(t_cam) * obj_list->nb_camera);
		if (!obj_list->camera)
			return (rt_error("Memory allocation failed."));
	}
	if (obj_list->nb_spot)
	{
		obj_list->spot = malloc(sizeof(t_light) * obj_list->nb_spot);
		if (!obj_list->spot)
			return (rt_error("Memory allocation failed."));
	}
	return (0);
}

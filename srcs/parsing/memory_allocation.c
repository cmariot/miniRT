/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_allocation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 18:01:44 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/08 13:01:36 by cmariot          ###   ########.fr       */
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
		ft_bzero(obj_list->objs, sizeof(t_obj) * obj_list->nb_objs);
	}
	if (obj_list->nb_camera)
	{
		obj_list->camera = malloc(sizeof(t_cam) * obj_list->nb_camera);
		if (!obj_list->camera)
			return (rt_error("Memory allocation failed."));
		ft_bzero(obj_list->camera, sizeof(t_cam) * obj_list->nb_camera);
	}
	if (obj_list->nb_spot)
	{
		obj_list->spot = malloc(sizeof(t_light) * obj_list->nb_spot);
		if (!obj_list->spot)
			return (rt_error("Memory allocation failed."));
		ft_bzero(obj_list->spot, sizeof(t_light) * obj_list->nb_spot);
	}
	return (0);
}

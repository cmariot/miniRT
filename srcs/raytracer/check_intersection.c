/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:36:55 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/08 16:54:05 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	check_intersection(t_cam *camera, t_obj_list *obj_list,
	t_3d *position, t_3d *normale)
{
	int		pixel_color;
	double	max_distance;
	double	distance;
	size_t	i;

	i = 0;
	max_distance = INFINITY;
	pixel_color = obj_list->ambient.color.trgb;
	while (i < obj_list->nb_objs)
	{
		if (obj_list->objs[i].intersection(obj_list->objs[i],
				camera[0].ray, position, normale))
		{
			distance = length(camera->position, *position);
			if (distance <= max_distance)
			{
				pixel_color = illumination(obj_list->objs[i], obj_list,
						*normale, *position);
				max_distance = distance;
			}
		}
		i++;
	}
	return (pixel_color);
}

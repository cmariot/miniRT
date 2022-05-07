/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_intersection.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 20:36:55 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/07 16:28:39 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	print_vector(char *vector_name, t_3d vector)
{
	printf("%s\n", vector_name);
	printf("X : %.3f, Y = %.3f, Z = %.3f\n", vector.x, vector.y, vector.z);
}

int	check_intersection(t_cam *camera, t_obj_list *obj_list,
	t_3d *position, t_3d *normale)
{
	int		pixel_color;
	double	max_distance;
	double	distance;
	size_t	i;
//	t_3d	second_ray_pos;
//	t_3d	second_ray_dir;

	i = 0;
	max_distance = INFINITY;
	pixel_color = obj_list->ambient.color.trgb;
	while (i < obj_list->nb_objs)
	{
		if (obj_list->objs[i].intersection(obj_list->objs[i],
				camera[0], position, normale))
		{
			//second_ray_pos = *position;
			//second_ray_dir = normalize(sub_vector(obj_list->spot[0].position, *position));
			//bool has_inter_light = intersection_light();
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

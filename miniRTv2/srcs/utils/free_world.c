/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:04:10 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 16:36:33 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_world(t_world *world)
{
	size_t	index_cam;
	size_t	index_image;

	if (world->obj_list.objs)
		free(world->obj_list.objs);
	if (world->camera)
	{
		index_cam = 0;
		while (index_cam < world->obj_list.nb_camera)
		{
			index_image = 0;
			while (index_image < world->camera[index_cam].nb_image)
			{
				if (world->camera[index_cam].image[index_image].str_image)
					free(world->camera[index_cam].image[index_image].str_image);
				index_image++;
			}
			if (world->camera[index_cam].image)
				free(world->camera[index_cam].image);
			index_cam++;
		}
		free(world->camera);
	}
	if (world->light_list.spot_light)
		free(world->light_list.spot_light);
}

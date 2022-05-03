/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:03:29 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 10:44:30 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	parsing(t_world *world, const char *filename)
{
	if (check_extension(filename, ".rt"))
		return (1);
	if (check_reading_access(filename))
		return (1);
	if (get_object_list(&world->obj_list, filename))
		return (1);
	if (memory_allocation(world, &world->obj_list, &world->light_list))
		return (1);
	if (fill_world(world, filename))
		return (1);
	print_structure(world, &world->obj_list);
	free(world->obj_list.objs);
	free(world->camera);
	free(world->light_list.spot_light);
	return (0);
}

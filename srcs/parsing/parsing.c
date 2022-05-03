/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:03:29 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 23:42:23 by cmariot          ###   ########.fr       */
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
	if (memory_allocation(&world->obj_list))
		return (free_world(world));
	if (fill_world(world, filename))
		return (free_world(world));
	print_structure(world->obj_list);
	return (0);
}

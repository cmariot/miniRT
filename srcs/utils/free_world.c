/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:04:10 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 23:46:42 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	free_world(t_world *world)
{
	if (world->obj_list.objs)
		free(world->obj_list.objs);
	if (world->obj_list.camera)
		free(world->obj_list.camera);
	if (world->obj_list.spot)
		free(world->obj_list.spot);
	return (1);
}

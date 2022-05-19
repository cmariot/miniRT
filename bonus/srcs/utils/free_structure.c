/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structure.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:04:10 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/19 14:49:59 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	free_structure(t_world *world)
{
	if (world->obj_list.obj)
		free(world->obj_list.obj);
	if (world->obj_list.light)
		free(world->obj_list.light);
	return (1);
}

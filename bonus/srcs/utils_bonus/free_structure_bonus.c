/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structure_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:04:10 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/21 20:43:13 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	free_structure(t_world *world)
{
	if (world->obj_list.obj)
		free(world->obj_list.obj);
	if (world->obj_list.light)
		free(world->obj_list.light);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_translation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rballage <rballage@student.42.fr>            +#+  +:+       +#+      */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 14:00:44 by rballage           #+#    #+#            */
/*   Updated: 2022/06/01 18:32:51 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static void	translate(t_v3 *target, t_v3 *value)
{
	target->x -= value->x;
	target->y -= value->y;
	target->z -= value->z;
}

void	translate_sphere(t_obj *sphere, t_v3 cam_position)
{
	translate(&sphere->position, &cam_position);
}

void	translate_cylinder(t_obj *cylinder, t_v3 cam_position)
{
	translate(&cylinder->position, &cam_position);
	translate(&cylinder->ext1, &cam_position);
	translate(&cylinder->ext2, &cam_position);
}

void	translate_plan(t_obj *plan, t_v3 cam_position)
{
	translate(&plan->position, &cam_position);
}

// Translation des objets passée en methode / ptr fonction pour
// éviter une forêt de if
void	translate_all(t_obj_list *obj_list, t_cam *cam)
{
	size_t	i;

	i = 0;
	while (i < obj_list->nb_obj)
	{
		obj_list->obj[i].translate(&obj_list->obj[i], cam->position);
		i++;
	}
	translate(&(obj_list->light.position), &cam->position);
	cam->position = (const t_v3){0};
}

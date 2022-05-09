/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 15:24:37 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/09 17:05:59 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	is_shadow(t_obj_list *obj_list, t_3d *position, t_3d *normale)
{
	t_ray	secondary;
	t_3d	n2;
	t_3d	p2;
	size_t	i;
	size_t	j;

	(void)normale;
	secondary.position = *position;
	i = 0;
	while (i < obj_list->nb_spot)
	{
		secondary.direction = normalize(add_vector(*position,
					obj_list->spot[i].position));
		j = 0;
		while (j < obj_list->nb_objs)
		{
			if (obj_list->objs[j].intersection(obj_list->objs[j],
					secondary, &p2, &n2))
				if (norm(add_vector(*position, p2))
					<= norm(add_vector(*position, obj_list->spot[i].position)))
					return (false);
			j++;
		}
		i++;
	}
	return (false);
}

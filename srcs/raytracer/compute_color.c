/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:41:28 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/17 14:25:33 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/*
 * Pour chaque objet de la liste, si le rayon traverse l'objet et
 * si la distance entre la camera et cet objet est inferieure à celle
 * des precedents objets on calcule la couleur du pixel
 */

void	compute_color(int *color, t_ray *first_ray, t_obj_list *obj_list)
{
	double	max_distance;
	t_ray	second_ray;
	size_t	i;

	*color = 0;
	max_distance = INFINITY;
	i = 0;
	while (i < obj_list->nb_obj)
	{
		if (obj_list->obj[i].intersection(obj_list->obj[i], first_ray))
		{
			if (first_ray->t < max_distance)
			{
				max_distance = first_ray->t;
				second_ray = second_ray_generator(first_ray, obj_list->light);
				if (is_shadow(&second_ray, obj_list->light, obj_list))
					*color = compute_reflexion(obj_list->obj[i].color,
							*obj_list, second_ray);
				else
					*color = compute_reflexion(obj_list->obj[i].color,
							*obj_list, *first_ray);
			}
		}
		i++;
	}
}

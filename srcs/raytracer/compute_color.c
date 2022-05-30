/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:41:28 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/19 19:18:05 by cmariot          ###   ########.fr       */
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
	t_color	pixel_color;
	double	obj_distance;
	t_ray	second_ray;
	size_t	i;

	// ft_bzero(&pixel_color, sizeof(t_color));
	pixel_color = (const t_color){0};
	obj_distance = INFINITY;
	i = 0;
	while (i < obj_list->nb_obj)
	{
		if (obj_list->obj[i].intersection(&obj_list->obj[i], first_ray))
		{
			if (first_ray->t < obj_distance)
			{
				obj_distance = first_ray->t;
				pixel_color = ambient(&obj_list->obj[i], &obj_list->ambient);
				second_ray = second_ray_generator(first_ray, &obj_list->light);
				if (in_light(&second_ray, &obj_list->light, obj_list))
					diffuse(&pixel_color, &obj_list->obj[i].color, obj_list);
			}
		}
		i++;
	}
	*color = trgb_color(0, pixel_color.r, pixel_color.g, pixel_color.b);
}

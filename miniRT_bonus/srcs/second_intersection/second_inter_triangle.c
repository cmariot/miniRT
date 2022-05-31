/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   second_inter_triangle.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 18:22:25 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/31 14:14:47 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"
//
// static void	get_triangle_normale(t_ray *ray, t_obj *obj)
// {
// 	t_v3	ab;
// 	t_v3	ac;
//
// 	ab = sub_lvalue(&obj->b, &obj->a);
// 	ac = sub_lvalue(&obj->c, &obj->a);
// 	ray->normale = normalize(cross_lvalue(&ab, &ac));
// }

static bool	pts_lies_in_triangle(t_ray *ray, t_obj *obj)
{
	t_v3	c[3];
	t_v3	p;
	t_v3	norm_pbc;
	t_v3	norm_pca;
	t_v3	norm_pab;

	p = ray->intersection;
	c[0] = sub_lvalue(&obj->a, &p);
	c[1] = sub_lvalue(&obj->b, &p);
	c[2] = sub_lvalue(&obj->c, &p);
	norm_pbc = cross_lvalue(&c[1], &c[2]);
	norm_pca = cross_lvalue(&c[2], &c[0]);
	if (dot_lvalue(&norm_pbc, &norm_pca) < 0.0)
		return (false);
	norm_pab = cross_lvalue(&c[0], &c[1]);
	if (dot_lvalue(&norm_pbc, &norm_pab) < 0.0)
		return (false);
	return (true);
}

bool	second_intersection_triangle(t_obj *obj, t_ray *ray)
{
	// t_v3	inverse_normale;
	double angle;

	angle = dot_lvalue(&obj->direction, &ray->direction);
	if (fabs(angle) < 1e-6)
		return (false);
	ray->normale = obj->direction;
	// inverse_normale = multiply_lvalue(&ray->normale, -1.0);
	ray->t = (dot(ray->normale, sub(obj->a, ray->position)) / angle);
	if (ray->t < 0)
		return (false);
	ray->intersection = add(ray->position, multiply_lvalue(&ray->direction,
			ray->t));
	// if (norm_square(add_lvalue(&ray->intersection, &ray->normale))
	// 	> norm_square(add_lvalue(&ray->intersection, &inverse_normale)))
	// 	ray->normale = inverse_normale;
	return (pts_lies_in_triangle(ray, obj));
}

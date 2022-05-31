/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:33:20 by cmariot           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/05/31 08:32:55 by cmariot          ###   ########.fr       */
=======
/*   Updated: 2022/05/30 19:00:50 by rballage         ###   ########.fr       */
>>>>>>> 49a8b99c3cd1db679c63da8838eb7e7b48ed2df0
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	translate_triangle(t_obj *triangle, t_v3 cam_position)
{
	translate(&triangle->a, cam_position);
	translate(&triangle->b, cam_position);
	translate(&triangle->c, cam_position);
}

static void	get_triangle_normale(t_obj *obj)
{
	t_v3	ab;
	t_v3	ac;

	ab = sub_lvalue(&obj->b, &obj->a);
	ac = sub_lvalue(&obj->c, &obj->a);
	obj->direction = normalize(cross_lvalue(&ab, &ac));
	// obj->direction.x *= -1.0;
	// obj->direction.y *= -1.0;
	// obj->direction.z *= -1.0;
}

int	new_triangle(t_obj *triangle, char **array)
{
	triangle->intersection = &intersection_triangle;
	triangle->second_intersection = &second_intersection_triangle;
	triangle->print = &print_triangle;
	triangle->translate = &translate_triangle;
	if (ft_arraylen(array) != 5)
		return (rt_error("Invalid triangle declaration."));
	else if (set_position(&(triangle->a), array[1]))
		return (rt_error("Syntax error : triangle position"));
	else if (set_position(&(triangle->b), array[2]))
		return (rt_error("Syntax error : triangle position"));
	else if (set_position(&(triangle->c), array[3]))
		return (rt_error("Syntax error : triangle position"));
	else if (set_colors(&(triangle->color), array[4]))
		return (rt_error("Syntax error : triangle color"));
	get_triangle_normale(triangle);
	triangle->radius = dot_lvalue(&triangle->direction, &triangle->a);
	return (0);
}

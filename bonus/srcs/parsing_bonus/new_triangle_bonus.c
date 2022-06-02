/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_triangle_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:33:20 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/31 14:05:04 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

void	translate_triangle(t_obj *triangle, t_v3 cam_position)
{
	translate(&triangle->a, cam_position);
	translate(&triangle->b, cam_position);
	translate(&triangle->c, cam_position);
}

static void	get_triangle_normale(t_obj *triangle)
{
	t_v3	ab;
	t_v3	ac;

	ab = sub_lvalue(&triangle->b, &triangle->a);
	ac = sub_lvalue(&triangle->c, &triangle->a);
	triangle->direction = normalize(cross_lvalue(&ab, &ac));
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

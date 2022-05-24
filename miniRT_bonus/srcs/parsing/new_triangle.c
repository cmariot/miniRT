/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_triangle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:33:20 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/20 14:49:03 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_triangle(t_obj *plan, char **array)
{
	plan->intersection = &intersection_triangle;
	plan->second_intersection = &intersection_triangle;
	plan->print = &print_triangle;
	plan->translate = &translate_triangle;
	if (ft_arraylen(array) != 5)
		return (rt_error("Invalid triangle declaration."));
	else if (set_position(&(plan->a), array[1]))
		return (rt_error("Syntax error : triangle position"));
	else if (set_position(&(plan->b), array[2]))
		return (rt_error("Syntax error : triangle position"));
	else if (set_position(&(plan->c), array[3]))
		return (rt_error("Syntax error : triangle position"));
	else if (set_colors(&(plan->color), array[4]))
		return (rt_error("Syntax error : triangle color"));
	return (0);
}

//intersection_triangle
//second_intersection_triangle
//print_triangle
//translate_triangle

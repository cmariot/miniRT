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
	plan->second_intersection = &second_intersection_triangle;
	plan->print = &print_triangle;
	plan->translate = &translate_triangle;
	if (ft_arraylen(array) != 5)
		return (rt_error("Invalid triangle declaration."));
	else if (set_position(&(plan->ext1), array[1]))
		return (rt_error("Syntax error : triangle position"));
	else if (set_position(&(plan->ext2), array[1]))
		return (rt_error("Syntax error : triangle position"));
	else if (set_position(&(plan->axe), array[1]))
		return (rt_error("Syntax error : triangle position"));
	else if (set_colors(&(plan->color), array[3]))
		return (rt_error("Syntax error : triangle color"));
	return (0);
}

//intersection_triangle
//second_intersection_triangle
//print_triangle
//translate_triangle

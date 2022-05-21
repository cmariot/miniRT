/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:33:20 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/20 14:49:03 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_plan(t_obj *plan, char **array)
{
	plan->intersection = &intersection_plan;
	plan->second_intersection = &second_intersection_plan;
	plan->print = &print_plan;
	plan->translate = &translate_plan;
	if (ft_arraylen(array) != 4)
		return (rt_error("Invalid plan declaration."));
	else if (set_position(&(plan->position), array[1]))
		return (rt_error("Syntax error : Plan position"));
	else if (set_direction(&(plan->direction), array[2]))
		return (rt_error("Syntax error : Plan direction"));
	else if (set_colors(&(plan->color), array[3]))
		return (rt_error("Syntax error : Plan color"));
	return (0);
}

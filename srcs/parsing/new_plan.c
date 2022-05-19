/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:33:20 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/19 19:30:01 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_plan(t_obj *o_plan, char **array)
{
	o_plan->intersection = &intersection_plan;
	o_plan->second_intersection = &second_intersection_plan;
	o_plan->print = &print_plan;
	o_plan->type = plan;
	if (ft_arraylen(array) != 4)
		return (rt_error("Invalid plan declaration."));
	else if (set_position(&(o_plan->position), array[1]))
		return (rt_error("Syntax error : Plan position"));
	else if (set_direction(&(o_plan->direction), array[2]))
		return (rt_error("Syntax error : Plan direction"));
	else if (set_colors(&(o_plan->color), array[3]))
		return (rt_error("Syntax error : Plan color"));
	return (0);
}

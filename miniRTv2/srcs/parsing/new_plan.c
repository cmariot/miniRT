/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:33:20 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 16:24:44 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_obj	new_plan(char **array, int *error)
{
	t_obj	plan;

	plan.print = &print_plan;
	if (ft_arraylen(array) != 4)
		*error = rt_error("Too much arguments in plan declaration.");
	else if (set_position(&(plan.position), array[1]))
		*error = 1;
	else if (set_direction(&(plan.direction), array[2]))
		*error = 1;
	else if (set_colors(&(plan.color), array[3]))
		*error = 1;
	return (plan);
}

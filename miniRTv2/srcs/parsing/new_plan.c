/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:33:20 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 08:51:21 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	fill_plan(t_obj *plan, char **array)
{
	if (ft_arraylen(array) != 4)
		return (rt_error("Syntax error : Plan line syntax."));
	if (set_position(&(plan->position), array[1]))
		return (1);
	if (set_direction(&(plan->direction), array[2]))
		return (1);
	if (set_colors(&(plan->color), array[3]))
		return (1);
	return (0);
}

t_obj	new_plan(char **array, int *error)
{
	t_obj	plan;

	plan.print = &print_plan;
	*error = fill_plan(&plan, array);
	return (plan);
}

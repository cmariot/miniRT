/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_plan.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 19:33:20 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 23:01:32 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_plan(t_obj *plan, char **array)
{
	plan->print = &print_plan;
	if (ft_arraylen(array) != 4)
		return (rt_error("Too much arguments in plan declaration."));
	else if (set_position(&(plan->position), array[1]))
		return (1);
	else if (set_direction(&(plan->direction), array[2]))
		return (1);
	else if (set_colors(&(plan->color), array[3]))
		return (1);
	return (0);
}

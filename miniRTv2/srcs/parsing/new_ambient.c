/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:36:47 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 16:26:35 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_amb	new_ambient(char **array, int *error)
{
	t_amb	ambient;

	if (ft_arraylen(array) != 3)
	{
		*error = rt_error("Too much arguments in ambient light declaration.");
		ambient.ratio = 0;
	}
	else if (set_double(&(ambient.ratio), array[1], 0.0, 1.0))
		*error = second_line_error("Ambient light ratio.");
	else if (set_colors(&(ambient.color), array[2]))
		*error = second_line_error("Ambient light color");
	return (ambient);
}

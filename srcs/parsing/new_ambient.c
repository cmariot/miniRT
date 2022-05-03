/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:36:47 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 23:22:46 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_ambient(t_amb *ambient, char **array)
{
	ambient->print = &print_ambient;
	if (ft_arraylen(array) != 3)
		return (rt_error("Too much arguments in ambient light declaration."));
	if (set_double(&(ambient->ratio), array[1], 0.0, 1.0))
		return (second_line_error("Ambient light ratio."));
	if (set_colors(&(ambient->color), array[2]))
		return (second_line_error("Ambient light color"));
	return (0);
}

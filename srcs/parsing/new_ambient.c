/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:36:47 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/11 16:47:56 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	new_ambient(t_amb *ambient, char **array)
{
	ambient->print = &print_ambient;
	if (ft_arraylen(array) != 3)
		return (rt_error("Invalid ambient light declaration."));
	if (set_double(&(ambient->ratio), array[1], 0.0, 1.0))
		return (rt_error("Syntax error : Ambient ratio"));
	if (set_colors(&(ambient->color), array[2]))
		return (rt_error("Syntax error : Ambient color"));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:08:58 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/11 17:49:46 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	rt_error(char const *error_message)
{
	red();
	print(2, "Error\n");
	print(2, "%s\n", error_message);
	reset_color();
	return (1);
}

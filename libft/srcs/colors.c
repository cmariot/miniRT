/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 04:02:55 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 21:42:43 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	trgb_color(int t, double r, double g, double b)
{
	r = fmax(0, fmin(r, 255));
	g = fmax(0, fmin(g, 255));
	b = fmax(0, fmin(b, 255));
	return ((int)t << 24 | (int)r << 16 | (int)g << 8 | (int)b);
}

void	red(void)
{
	write(1, "\033[1;31m", 7);
}

void	green(void)
{
	write(1, "\033[1;32m", 7);
}

void	reset_color(void)
{
	write(1, "\033[0m", 4);
}

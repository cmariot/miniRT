/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 04:02:55 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/04 20:48:20 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	trgb_color(int t, int r, int g, int b)
{
	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	return (t << 24 | r << 16 | g << 8 | b);
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

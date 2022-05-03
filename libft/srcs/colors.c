/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 04:02:55 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 21:58:33 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	trgb_color(int t, int r, int g, int b)
{
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

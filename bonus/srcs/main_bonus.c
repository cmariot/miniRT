/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 22:21:02 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/11 13:36:35 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT_bonus.h"

int	main(int argc, char **argv)
{
	t_world		world;

	if (argc == 2)
	{
		if (parsing(&world, argv[1]))
			return (1);
		if (open_window(&world))
			return (1);
		return (0);
	}
	else
		return (rt_error("Wrong number of arguments."));
}

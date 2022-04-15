/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:57:45 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/15 10:47:25 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int argc, char **argv)
{
	t_scene	rt_scene;

	if (argc == 2)
	{
		if (parse_scene(argv[1], &rt_scene))
			return (1);
		if (open_window(&rt_scene))
			return (1);
		return (0);
	}
	else
		return (rt_error("Wrong number of arguments."));
}

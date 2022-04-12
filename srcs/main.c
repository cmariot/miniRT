/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:57:45 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/11 08:38:01 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	rt_error(char const *error_message, bool DISPLAY_ERROR)
{
	red();
	if (DISPLAY_ERROR == true)
		print(2, "Error\n");
	print(2, "%s\n", error_message);
	reset_color();
	return (1);
}

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
		return (rt_error("Wrong number of arguments.", true));
}

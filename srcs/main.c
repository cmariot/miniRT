/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 21:57:45 by cmariot           #+#    #+#             */
/*   Updated: 2022/03/20 17:31:09 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	rt_error(char const *error_message)
{
	print(2, "Error\n");
	print(2, "%s\n", error_message);
	return (1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		print(1, "%s\n", argv[1]);
		return (0);
	}
	else
		return (rt_error("Wrong number of arguments."));
}

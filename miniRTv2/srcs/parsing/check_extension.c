/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:08:00 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/03 01:08:50 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* This function check if the filename given as argument has the correct
 * extension, the miniRT scene file must have the '.rt' extension */

int	check_extension(const char *filename, const char *extension)
{
	size_t	filename_index;
	size_t	extension_index;

	if (ft_strlen(filename) < ft_strlen(extension))
		return (rt_error("The scene must have the .rt extension."));
	filename_index = ft_strlen(filename) - 1;
	extension_index = ft_strlen(extension) - 1;
	while (extension_index + 1 != 0)
		if (filename[filename_index--] != extension[extension_index--])
			return (rt_error("The scene must have the .rt extension."));
	return (0);
}

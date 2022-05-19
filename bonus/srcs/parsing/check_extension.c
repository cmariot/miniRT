/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 23:08:00 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/12 08:49:27 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* This function check if the filename given as argument has the correct
 * extension, the miniRT scene file must have the '.rt' extension */

int	check_extension(const char *filename, const char *extension)
{
	size_t	filename_len;
	size_t	extension_len;

	filename_len = ft_strlen(filename);
	extension_len = ft_strlen(extension);
	if (filename_len-- < extension_len--)
		return (rt_error("The scene must have the .rt extension."));
	while (extension_len + 1 != 0)
		if (filename[filename_len--] != extension[extension_len--])
			return (rt_error("The scene must have the .rt extension."));
	return (0);
}

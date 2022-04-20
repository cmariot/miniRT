/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_structure.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:21:32 by cmariot           #+#    #+#             */
/*   Updated: 2022/04/15 18:08:14 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_STRUCTURE_H
# define MLX_STRUCTURE_H

# include <mlx.h>

# define SIZE_X 1440
# define SIZE_Y 872

//MacOS
# define ESC_KEY 53
//Linux
//# define ESC_KEY 65307

# define PI 3.14159265359

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

#endif

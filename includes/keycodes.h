/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:38:11 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/18 16:02:35 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# if defined __APPLE__
#  define ESC_KEY 53
#  define C_KEY 8
#  define L_KEY 37

# elif defined unix
#  define ESC_KEY 65307
#  define LEFT_KEY 65361
#  define RIGHT_KEY 65363
#  define TOP_KEY 65362
#  define BOTTOM_KEY 65364

# endif

#endif

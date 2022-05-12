/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 10:38:11 by cmariot           #+#    #+#             */
/*   Updated: 2022/05/08 12:44:51 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# if defined __APPLE__
#  define ESC_KEY 53
//#  define RED_CROSS

# elif defined unix
#  define ESC_KEY 65307
//#  define RED_CROSS

# endif

#endif

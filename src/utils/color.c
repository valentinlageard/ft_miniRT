/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 03:12:36 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/16 03:15:17 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	*coltovec3(t_color *color)
{
	double	red;
	double	green;
	double	blue;

	red = (double)color->red / 255.0;
	green = (double)color->green / 255.0;
	blue = (double)color->blue / 255.0;
	return (new_vec3(red, green, blue));
}
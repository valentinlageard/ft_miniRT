/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/16 03:12:36 by vlageard          #+#    #+#             */
/*   Updated: 2020/05/11 15:28:43 by vlageard         ###   ########.fr       */
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

t_vec3	*get_ambient(t_color *color, double intensity)
{
	t_vec3	*vcolor;
	t_vec3	*vintensity;
	t_vec3	*res_vcolor;

	vcolor = coltovec3(color);
	vintensity = new_vec3(intensity, intensity, intensity);
	res_vcolor = vec3_mul(vcolor, vintensity);
	free(vcolor);
	free(vintensity);
	return (res_vcolor);
}
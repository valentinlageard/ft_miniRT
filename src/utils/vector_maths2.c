/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_maths2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:59:45 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/22 16:44:09 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		vec3_is_equal(t_vec3 *vec1, t_vec3 *vec2)
{
	return (vec1->x == vec2->x && vec1->y == vec2->y && vec1->z == vec2->z);
}

double	vec3_magnitude(t_vec3 *vec3)
{
	return (sqrt(vec3_dot(vec3, vec3)));
}

t_vec3	*vec3_normalize(t_vec3 *vec3)
{
	double	magnitude;

	magnitude = vec3_magnitude(vec3);
	return (new_vec3(vec3->x / magnitude, vec3->y / magnitude,
		vec3->z / magnitude));
}

double	vec3_cos_angle(t_vec3 *vec1, t_vec3 *vec2)
{
	double	dot;
	double	magnitude1;
	double	magnitude2;

	dot = vec3_dot(vec1, vec2);
	magnitude1 = vec3_magnitude(vec1);
	magnitude2 = vec3_magnitude(vec2);
	return (dot / (magnitude1 * magnitude2));
}

t_vec3	*vec3_clamp(t_vec3 *vec, double max)
{
	double	x;
	double	y;
	double	z;

	x = vec->x <= max ? vec->x : max;
	y = vec->y <= max ? vec->y : max;
	z = vec->z <= max ? vec->z : max;
	return (new_vec3(x, y, z));
}

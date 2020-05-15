/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_maths2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/15 19:59:45 by vlageard          #+#    #+#             */
/*   Updated: 2020/05/12 03:16:05 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	vec3_is_equal(t_vec3 *vec1, t_vec3 *vec2)
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
	return(new_vec3(vec3->x/magnitude,vec3->y/magnitude,vec3->z/magnitude));
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

double	vec3_get_distance(t_vec3 *vec1, t_vec3 *vec2)
{
	double	x;
	double	y;
	double	z;

	x = pow(vec2->x - vec1->x, 2);
	y = pow(vec2->y - vec1->y, 2);
	z = pow(vec2->z - vec1->z, 2);
	return (pow(x + y + z, 0.5));
}

t_vec3	*vec3_get_nvec3_between(t_vec3 *vec1, t_vec3 *vec2)
{
	t_vec3	*tmp;
	t_vec3	*result;

	tmp = vec3_sub(vec1, vec2);
	result = vec3_normalize(tmp);
	free(tmp);
	return (result);
}

t_vec3	*vec3_cross(t_vec3 *vec1, t_vec3 *vec2)
{
	t_vec3	*cross;
	double	x;
	double	y;
	double	z;

	x = vec1->y * vec2->z - vec1->z * vec2->y;
	y = vec1->z * vec2->x - vec1->x * vec2->z;
	z = vec1->x * vec2->y - vec1->y * vec2->x;
	cross = new_vec3(x, y, z);
	return (cross);
}
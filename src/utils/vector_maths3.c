/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_maths3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/22 16:43:49 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/22 16:43:58 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

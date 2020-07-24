/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_maths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:18:46 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/22 16:42:39 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3	*vec3_add(t_vec3 *vec1, t_vec3 *vec2)
{
	return (new_vec3(vec1->x + vec2->x, vec1->y + vec2->y, vec1->z + vec2->z));
}

t_vec3	*vec3_sub(t_vec3 *vec1, t_vec3 *vec2)
{
	return (new_vec3(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z));
}

t_vec3	*vec3_mul(t_vec3 *vec1, t_vec3 *vec2)
{
	return (new_vec3(vec1->x * vec2->x, vec1->y * vec2->y, vec1->z * vec2->z));
}

t_vec3	*vec3_div(t_vec3 *vec1, t_vec3 *vec2)
{
	return (new_vec3(vec1->x / vec2->x, vec1->y / vec2->y, vec1->z / vec2->z));
}

double	vec3_dot(t_vec3 *vec1, t_vec3 *vec2)
{
	return (vec1->x * vec2->x + vec1->y * vec2->y + vec1->z * vec2->z);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:23:23 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/10 15:39:25 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	*new_vec3(double x, double y, double z)
{
	t_vec3	*new_vec3;

	if (!(new_vec3 = (t_vec3 *)malloc(sizeof(t_vec3))))
		return (NULL);
	new_vec3->x = x;
	new_vec3->y = y;
	new_vec3->z = z;
	return (new_vec3);
}

int	vec3_is_equal(t_vec3 *vec1, t_vec3 *vec2)
{
	return (vec1->x == vec2->x && vec1->y == vec2->y && vec1->z == vec2->z);
}
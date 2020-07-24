/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 15:23:23 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/24 17:51:27 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

t_vec3	*vec3_cpy(t_vec3 *vec3)
{
	return (new_vec3(vec3->x,vec3->y,vec3->z));
}


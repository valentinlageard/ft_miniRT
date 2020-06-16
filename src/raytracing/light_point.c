/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 19:18:55 by vlageard          #+#    #+#             */
/*   Updated: 2020/06/16 18:31:37 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_light_p	*new_light_p(t_vec3 *hit_p, t_vec3 *normal, t_vec3 *vcolor, t_object *object)
{
	t_light_p	*new_light_point;

	if (!(new_light_point = (t_light_p *)malloc(sizeof(t_light_p))))
		return (NULL);
	new_light_point->hit_p = hit_p;
	new_light_point->normal = normal;
	new_light_point->vcolor = vcolor;
	new_light_point->object = object;
	return (new_light_point);
}

void free_lp(t_light_p *lp)
{
	free(lp->hit_p);
	free(lp->normal);
	free(lp->vcolor);
	free(lp);
}
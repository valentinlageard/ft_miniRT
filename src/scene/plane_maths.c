/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_maths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:39:56 by vlageard          #+#    #+#             */
/*   Updated: 2020/05/05 19:24:43 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3	*get_normal_plane(t_ray *ray, t_plane *plane)
{
	t_vec3	*tmp;
	t_vec3	*rot_normal;
	t_vec3	*inv_normal;

	tmp = new_vec3(0.0,0.0,1.0);
	rot_normal = vec3_rotateXYZ(tmp, plane->orientation);
	free(tmp);
	if (vec3_cos_angle(rot_normal, ray->dir) > 0)
	{
		tmp = new_vec3(-1.0, -1.0, -1.0);
		inv_normal = vec3_mul(rot_normal, tmp);
		free(tmp);
		free(rot_normal);
		return (inv_normal);
	}
	else
		return (rot_normal);
}

double	intersect_plane(t_ray *ray, t_plane *plane)
{
	t_vec3	*tmp;
	t_vec3	*rot_normal;
	double	numer;
	double	denom;

	rot_normal = get_normal_plane(ray, plane);
	tmp = vec3_sub(plane->pos, ray->orig);
	numer = vec3_dot(tmp, rot_normal);
	free(tmp);
	denom = vec3_dot(ray->dir, rot_normal);
	// Gérer les rayons parallèles !
	free(rot_normal);
	return (numer / denom);
}

t_vec3	*get_hit_point_plane(t_ray *ray, t_plane *plane)
{
	double	t;
	double	hp_x;
	double	hp_y;
	double	hp_z;

	t = intersect_plane(ray, plane);
	hp_x = ray->orig->x + ray->dir->x * t;
	hp_y = ray->orig->y + ray->dir->y * t;
	hp_z = ray->orig->z + ray->dir->z * t;
	return (new_vec3(hp_x, hp_y, hp_z));
}

t_light_p	*get_light_p_plane(t_ray *ray, t_object *obj)
{
	t_plane		*plane;
	t_vec3		*hit_point;
	t_vec3		*normal;
	t_vec3		*vcolor;

	plane = (t_plane *)obj->object;
	hit_point = get_hit_point_plane(ray, plane);
	normal = get_normal_plane(ray, plane);
	vcolor = coltovec3(plane->color);
	return (new_light_p(hit_point, normal, vcolor, obj));
}
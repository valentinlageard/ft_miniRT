/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_maths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:34:06 by vlageard          #+#    #+#             */
/*   Updated: 2020/06/09 16:44:59 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vec3		*get_rraydir(t_ray *ray, t_vec3 *orient)
{
	t_vec3	*rorient;
	t_vec3	*rraydir;

	rorient = new_vec3(orient->x * -1.0, orient->y * -1.0, orient->z * -1.0);
	rraydir = vec3_rotateXYZ(ray->dir, rorient);
	free(rorient);
	return (rraydir);
}

double		intersect_cyl(t_ray *ray, t_cyl *cyl)
{
	double	a;
	double	b;
	double	c;
	t_vec3	*rraydir;

	rraydir = get_rraydir(ray, cyl->orientation);
	a = rraydir->x * rraydir->x + rraydir->z * rraydir->z;
	b = 2 * rraydir->x * (ray->orig->x - cyl->pos->x)
	+ 2 * rraydir->z * (ray->orig->z - cyl->pos->z);
	c = (ray->orig->x - cyl->pos->x) * (ray->orig->x - cyl->pos->x)
	+ (ray->orig->z - cyl->pos->z) * (ray->orig->z - cyl->pos->z)
	- (cyl->diameter / 2.0) * (cyl->diameter / 2.0);
	return (get_min_quadratic_solution(a, b, c));
	// Need to check if inside the cylinder size...
}

t_vec3		*get_hit_point_cyl(t_ray *ray, t_cyl * cyl)
{
	double	t;
	double	hp_x;
	double	hp_y;
	double	hp_z;
	t_vec3	*rraydir;

	rraydir = get_rraydir(ray, cyl->orientation);
	t = intersect_cyl(ray, cyl);
	hp_x = ray->orig->x + rraydir->x * t;
	hp_y = ray->orig->y + rraydir->y * t;
	hp_z = ray->orig->z + rraydir->z * t;
	free(rraydir);
	return (new_vec3(hp_x, hp_y, hp_z));
}

t_vec3		*get_normal_cyl(t_vec3 *hit_point)
{
	t_vec3	*tmp;
	t_vec3	*normal;
	
	tmp = new_vec3(2.0 * hit_point->x, 0.0, 2.0 * hit_point->z);
	normal = vec3_normalize(tmp);
	free(tmp);
	return (normal);
}

t_light_p	*get_light_p_cyl(t_ray *ray, t_object *obj)
{
	t_cyl		*cyl;
	t_vec3		*hit_point;
	t_vec3		*normal;
	t_vec3		*vcolor;

	cyl = (t_cyl *)obj->object;
	hit_point = get_hit_point_cyl(ray, cyl);
	normal = get_normal_cyl(hit_point);
	vcolor = coltovec3(cyl->color);
	return (new_light_p(hit_point, normal, vcolor, obj));
}
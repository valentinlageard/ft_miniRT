/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_maths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 19:24:30 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/29 14:56:01 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double		intersect_sphere(t_ray *ray, t_sphere *sphere)
{
	t_vec3	*oc;
	double	a;
	double	b;
	double	c;
	double	t;

	oc = vec3_sub(ray->orig, sphere->pos);
	a = vec3_dot(ray->dir, ray->dir);
	b = 2 * vec3_dot(ray->dir, oc);
	c = vec3_dot(oc, oc) - sphere->radius * sphere->radius;
	free(oc);
	t = get_min_quadratic_solution(a, b, c);
	if (t <= 0)
		t = get_max_quadratic_solution(a, b, c);
	return (t);
}

t_vec3		*get_hit_point_sphere(t_ray *ray, t_sphere *sphere)
{
	double	t;
	double	hp_x;
	double	hp_y;
	double	hp_z;

	t = intersect_sphere(ray, sphere);
	hp_x = ray->orig->x + ray->dir->x * t;
	hp_y = ray->orig->y + ray->dir->y * t;
	hp_z = ray->orig->z + ray->dir->z * t;
	return (new_vec3(hp_x, hp_y, hp_z));
}

t_vec3		*get_normal_sphere(t_vec3 *hit_p, t_ray *ray, t_sphere *sphere)
{
	t_vec3	*tmp;
	t_vec3	*normal;

	tmp = vec3_sub(hit_p, sphere->pos);
	normal = vec3_normalize(tmp);
	if (vec3_cos_angle(normal, ray->dir) > 0)
	{
		normal->x *= -1.0;
		normal->y *= -1.0;
		normal->z *= -1.0;
	}
	free(tmp);
	return (normal);
}

t_light_p	*get_light_p_sphere(t_ray *ray, t_object *obj)
{
	t_sphere	*sphere;
	t_vec3		*hit_point;
	t_vec3		*normal;
	t_vec3		*vcolor;

	sphere = (t_sphere *)obj->object;
	hit_point = get_hit_point_sphere(ray, sphere);
	normal = get_normal_sphere(hit_point, ray, sphere);
	vcolor = coltovec3(sphere->color);
	return (new_light_p(hit_point, normal, vcolor, obj));
}

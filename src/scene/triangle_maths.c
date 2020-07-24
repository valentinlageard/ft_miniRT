/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_maths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 23:27:22 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/22 16:38:57 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		*get_normal_tri(t_tri *tri)
{
	t_vec3	*ab;
	t_vec3	*ac;
	t_vec3	*normal;
	t_vec3	*norm_normal;

	ab = vec3_sub(tri->b, tri->a);
	ac = vec3_sub(tri->c, tri->a);
	normal = vec3_cross(ab, ac);
	norm_normal = vec3_normalize(normal);
	free(ab);
	free(ac);
	free(normal);
	return (norm_normal);
}

int			inout_check(t_vec3 *hit_point, t_vec3 *normal, t_vec3 *x, t_vec3 *y)
{
	t_vec3	*edge;
	t_vec3	*vxtohp;
	t_vec3	*cross;
	int		res;

	edge = vec3_sub(y, x);
	vxtohp = vec3_sub(hit_point, x);
	cross = vec3_cross(edge, vxtohp);
	if (vec3_dot(normal, cross) < 0)
		res = 0;
	else
		res = 1;
	free(edge);
	free(vxtohp);
	free(cross);
	return (res);
}

double		intersect_tri(t_ray *ray, t_tri *tri)
{
	t_vec3	*normal;
	double	t;
	t_vec3	*rayorig_to_tria;
	t_vec3	*hit_point;

	normal = get_normal_tri(tri);
	rayorig_to_tria = vec3_sub(tri->a, ray->orig);
	t = (vec3_dot(normal, rayorig_to_tria)) / vec3_dot(normal, ray->dir);
	free(rayorig_to_tria);
	hit_point = new_vec3(ray->orig->x + t * ray->dir->x,
		ray->orig->y + t * ray->dir->y,
		ray->orig->z + t * ray->dir->z);
	if (!(inout_check(hit_point, normal, tri->a, tri->b) &&
	inout_check(hit_point, normal, tri->b, tri->c) &&
	inout_check(hit_point, normal, tri->c, tri->a)))
		t = -1.0;
	free(normal);
	free(hit_point);
	return (t);
}

t_vec3		*get_hit_point_tri(t_ray *ray, t_tri *tri)
{
	double	t;
	double	x;
	double	y;
	double	z;

	t = intersect_tri(ray, tri);
	x = ray->orig->x + t * ray->dir->x;
	y = ray->orig->y + t * ray->dir->y;
	z = ray->orig->z + t * ray->dir->z;
	return (new_vec3(x, y, z));
}

t_light_p	*get_light_p_tri(t_ray *ray, t_object *obj)
{
	t_tri		*tri;
	t_vec3		*hit_point;
	t_vec3		*normal;
	t_vec3		*vcolor;

	tri = (t_tri *)obj->object;
	hit_point = get_hit_point_tri(ray, tri);
	normal = get_normal_tri(tri);
	if (vec3_cos_angle(ray->dir, normal) > 0)
	{
		normal->x *= -1.0;
		normal->y *= -1.0;
		normal->z *= -1.0;
	}
	vcolor = coltovec3(tri->color);
	return (new_light_p(hit_point, normal, vcolor, obj));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square_maths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:15:59 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/24 19:46:24 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec3		*get_normal_square(t_ray *ray, t_square *square)
{
	t_vec3	*tmp;
	t_vec3	*rot_normal;
	t_vec3	*inv_normal;

	tmp = new_vec3(0.0, 0.0, 1.0);
	rot_normal = vec3_rotatexyz(tmp, square->orientation);
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

int			check_inside_square(t_vec3 *e, t_vec3 *p_hit, t_square *square)
{
	t_vec3	*re;
	t_vec3	*v;
	double	res;

	re = vec3_rotatexyz(e, square->orientation);
	v = vec3_sub(p_hit, square->pos);
	res = vec3_dot(v, re) / vec3_magnitude(re);
	free(re);
	free(v);
	free(e);
	return (res >= 0 && res <= 1);
}

double		intersect_square(t_ray *ray, t_square *square)
{
	t_vec3	*tmp;
	t_vec3	*rot_normal;
	t_vec3	*p_hit;
	double	t;

	rot_normal = get_normal_square(ray, square);
	tmp = vec3_sub(square->pos, ray->orig);
	t = vec3_dot(tmp, rot_normal) / vec3_dot(ray->dir, rot_normal);
	free(tmp);
	free(rot_normal);
	p_hit = new_vec3(ray->orig->x + t * ray->dir->x,
		ray->orig->y + t * ray->dir->y,
		ray->orig->z + t * ray->dir->z);
	if (check_inside_square(new_vec3(square->size, 0, 0), p_hit, square) &&
		check_inside_square(new_vec3(0, square->size, 0), p_hit, square))
	{
		free(p_hit);
		return (t);
	}
	else
	{
		free(p_hit);
		return (-1.0);
	}
}

t_vec3		*get_hit_point_square(t_ray *ray, t_square *square)
{
	double	t;

	t = intersect_square(ray, square);
	return (new_vec3(ray->orig->x + t * ray->dir->x,
		ray->orig->y + t * ray->dir->y,
		ray->orig->z + t * ray->dir->z));
}

t_light_p	*get_light_p_square(t_ray *ray, t_object *obj)
{
	t_square	*square;
	t_vec3		*hit_point;
	t_vec3		*normal;
	t_vec3		*vcolor;

	square = (t_square *)obj->object;
	hit_point = get_hit_point_square(ray, square);
	normal = get_normal_square(ray, square);
	if (vec3_cos_angle(ray->dir, normal) > 0)
	{
		normal->x *= -1.0;
		normal->y *= -1.0;
		normal->z *= -1.0;
	}
	vcolor = coltovec3(square->color);
	return (new_light_p(hit_point, normal, vcolor, obj));
}

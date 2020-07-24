/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:35:14 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/24 17:18:18 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	*new_ray(t_vec3 *origin, t_vec3 *dir)
{
	t_ray	*new_ray;

	if (!(new_ray = (t_ray *)malloc(sizeof(t_ray))))
		return (NULL);
	new_ray->orig = origin;
	new_ray->dir = dir;
	return (new_ray);
}

void	free_ray(t_ray *ray)
{
	free(ray->orig);
	free(ray->dir);
	free(ray);
}

t_vec3	*get_ray_dir_unoriented(double u, double v, t_prog *prog)
{
	t_vec3	*p_pos;
	t_vec3	*ray_dir_unoriented;
	t_vec3	*world_origin;

	p_pos = new_vec3((2 * u - 1) * prog->half_width,
	(1 - 2 * v) * prog->half_height, -1);
	world_origin = new_vec3(0,0,0);
	if (!p_pos || !world_origin)
	{
		free(p_pos);
		free(world_origin);
		error_quit(prog, errno);
	}
	ray_dir_unoriented = vec3_sub(p_pos, world_origin);
	free(p_pos);
	free(world_origin);
	if (!(ray_dir_unoriented))
		error_quit(prog, errno);
	return (ray_dir_unoriented);
}

t_vec3	*get_ray_dir(double u, double v, t_prog *prog)
{
	t_vec3	*ray_dir_unoriented;
	t_vec3	*ray_dir_normalized;
	t_vec3	*cam_orientation;
	t_vec3	*ray_dir_oriented;

	ray_dir_unoriented = get_ray_dir_unoriented(u, v, prog);
	ray_dir_normalized = vec3_normalize(ray_dir_unoriented);
	cam_orientation = prog->current_cam->orientation;
	ray_dir_oriented = vec3_rotatexyz(ray_dir_normalized, cam_orientation);
	free(ray_dir_unoriented);
	free(ray_dir_normalized);
	return (ray_dir_oriented);
}

t_ray	*get_ray(int x, int y, t_prog *prog)
{
	t_ray	*ray;
	double	u;
	double	v;
	t_vec3	*cam_pos_cpy;
	t_vec3	*ray_dir;

	u = ((double)(x) + 0.5) / ((double)(prog->win_width));
	v = ((double)(y) + 0.5) / ((double)(prog->win_height));
	cam_pos_cpy = vec3_cpy(prog->current_cam->pos);
	ray_dir = get_ray_dir(u, v, prog);
	ray = new_ray(cam_pos_cpy, ray_dir);
	return (ray);
}

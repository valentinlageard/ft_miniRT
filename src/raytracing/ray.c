/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:35:14 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/15 02:15:07 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_ray	*new_ray(t_vec3 *origin, t_vec3 *dir)
{
	t_ray	*new_ray;

	if(!(new_ray = (t_ray *)malloc(sizeof(t_ray))))
		return (NULL);
	new_ray->orig = origin;
	new_ray->dir = dir;
	return(new_ray);
}

void	free_ray(t_ray *ray)
{
	free(ray->orig);
	free(ray->dir);
	free(ray);
}

t_vec3	*get_ray_dir(double u, double v, t_prog *prog)
{
	t_vec3	*p_pos;
	t_vec3	*ray_direction;
	t_vec3	*ray_direction_normalized;

	p_pos = new_vec3((2*u-1)*prog->half_width, (1-2*v)*prog->half_height,prog->current_cam->pos->z - 1);
	ray_direction = vec3_sub(p_pos, prog->current_cam->pos);
	ray_direction_normalized = vec3_normalize(ray_direction);
	free(p_pos);
	free(ray_direction);
	return (ray_direction_normalized);
}

t_ray	*get_ray(int x, int y, t_prog *prog)
{
	t_ray	*ray;
	double	u;
	double	v;

	u = ((double)(x)+0.5)/((double)(prog->win_width));
	v = ((double)(y)+0.5)/((double)(prog->win_height));
	//printf("u : %f / v : %f\n", u, v);
	ray = new_ray(vec3_cpy(prog->current_cam->pos), get_ray_dir(u, v, prog));
	return (ray);
}
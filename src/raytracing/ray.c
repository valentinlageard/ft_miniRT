/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 15:35:14 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/13 17:51:12 by vlageard         ###   ########.fr       */
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

t_ray	*get_ray(int x, int y, t_prog *prog)
{
	t_ray	*ray;
	double	u;
	double	v;
	double	dir_x;
	double	dir_y;
	double	dir_z;
	t_vec3	*direction;

	u = ((double)(x))/((double)(prog->win_width));
	v = ((double)(y))/((double)(prog->win_height));
	//printf("u : %f / v : %f\n", u, v);
	dir_x = prog->lower_left_corner->x + u * prog->horizontal->x + v * prog->vertical->x - prog->current_cam->pos->x;
	dir_y = prog->lower_left_corner->y + u * prog->horizontal->y + v * prog->vertical->y - prog->current_cam->pos->y;
	dir_z = prog->lower_left_corner->z + u * prog->horizontal->z + v * prog->vertical->z - prog->current_cam->pos->z;
	direction = new_vec3(dir_x, dir_y, dir_z);
	//printf("dir_x : %f / dir_y : %f / dir_z : %f\n", dir_x, dir_y, dir_z);
	ray = new_ray(new_vec3(prog->current_cam->pos->x, prog->current_cam->pos->y, prog->current_cam->pos->z), direction);
	return (ray);
}
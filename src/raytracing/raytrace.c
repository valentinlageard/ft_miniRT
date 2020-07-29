/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:42:55 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/29 17:01:07 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void		img_put_pixel(int x, int y, t_vec3 *vcolor, t_prog *prog)
{
	*(prog->img_pixels + ((y * prog->win_width) + x) * 4 + 2) =
	(int)(vcolor->x * 255);
	*(prog->img_pixels + (((y * prog->win_width) + x) * 4) + 1) =
	(int)(vcolor->y * 255);
	*(prog->img_pixels + (((y * prog->win_width) + x) * 4) + 0) =
	(int)(vcolor->z * 255);
	free(vcolor);
}

t_object	*collide_ray(t_ray *ray, t_prog *prog)
{
	t_object	*tmp;
	t_object	*current_hit;
	double		dist;
	double		new_dist;

	tmp = prog->objects;
	current_hit = NULL;
	dist = 1000.0;
	while (tmp != NULL)
	{
		new_dist = intersect_object(ray, tmp);
		if (new_dist < dist && new_dist >= 0)
		{
			dist = new_dist;
			current_hit = tmp;
		}
		tmp = tmp->next;
	}
	return (current_hit);
}

void		compute_xy(t_prog *prog)
{
	t_object		*current_hit;
	t_ray			*ray;
	t_vec3			*p_color;
	unsigned int	x;
	unsigned int	y;

	y = 0;
	while (y < prog->win_height)
	{
		x = 0;
		while (x < prog->win_width)
		{
			if (!(ray = get_ray(x, y, prog)))
				error_quit(prog, errno);
			if (!(current_hit = collide_ray(ray, prog)))
				p_color = new_vec3(0, 0, 0);
			else
				p_color = get_shading_point(ray, current_hit, prog);
			img_put_pixel(x, y, p_color, prog);
			free_ray(ray);
			x++;
		}
		y++;
	}
}

void		compute_image(t_prog *prog)
{
	init_img(prog);
	compute_camera_projection(prog);
	compute_xy(prog);
	if (prog->export == 1)
		export_bmp(prog);
	else
	{
		mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr,
			prog->img_ptr, 0, 0);
	}
	mlx_destroy_image(prog->mlx_ptr, prog->img_ptr);
}

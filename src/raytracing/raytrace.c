/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:42:55 by vlageard          #+#    #+#             */
/*   Updated: 2020/05/15 00:45:13 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	img_put_pixel(int x, int y, t_vec3 *vcolor, t_prog * prog)
{
	*(prog->img_pixels + ((y * prog->win_width) + x) * 4 + 2) = (int)(vcolor->x * 255);
	*(prog->img_pixels + (((y * prog->win_width) + x) * 4) + 1) = (int)(vcolor->y * 255);
	*(prog->img_pixels + (((y * prog->win_width) + x) * 4) + 0) = (int)(vcolor->z * 255);
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

void	compute_image(t_prog *prog)
{
	t_object	*current_hit;
	t_ray		*ray;
	int			x;
	int			y;
	t_vec3		*p_color;
	t_vec3		*black;

	black = new_vec3(0,0,0);
	x = 0;
	y = 0;
	init_img(prog);
	compute_camera_projection(prog);
	printf("win_width : %i / win_height : %i\n", prog->win_width, prog->win_height);
	printf("cam->pos : ");
	print_vec3(prog->current_cam->pos);
	printf("cam->dir : ");
	print_vec3(prog->current_cam->orientation);
	printf("cam->fov : %i\n", prog->current_cam->fov);
	printf("Rendering scene...\n");
	while (y < prog->win_height) // Pour chaque ligne
	{
		if (y % 10 == 0)
        	printf("-> Rendering line n°%d/%d\n", y, prog->win_height - 1);
		while (x < prog->win_width) // Pour chaque pixel dans cette ligne
		{	
			//printf("----------------\n");
			//printf("x : %i / y : %i\n", x, y);
			ray = get_ray(x, y, prog);
			//printf("ray->orig : ");
			//print_vec3(ray->orig);
			//printf("ray->dir : ");
			//print_vec3(ray->dir);
			current_hit = collide_ray(ray,prog);
			if (!current_hit)
				img_put_pixel(x, y, black, prog);
			else
			{
				p_color = get_shading_point(ray, current_hit, prog);
				img_put_pixel(x, y, p_color, prog);
				free(p_color);
			}
			free_ray(ray);
			x++;
		}
		y++;
		x = 0;
	}
	free(black);
	printf("Rendering done\n");
	mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_ptr, 0, 0);
	mlx_destroy_image(prog->mlx_ptr, prog->img_ptr);
}




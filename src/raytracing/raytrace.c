/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:42:55 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/13 18:03:39 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	test_color(int x, int y, t_object *current_hit, t_prog *prog)
{
	if (current_hit)
	{
		*(prog->img_pixels + ((y * prog->win_width) + x) * 4) = ((t_sphere *)(current_hit->object))->color->red;
		*(prog->img_pixels + (((y * prog->win_width) + x) * 4) + 1) = ((t_sphere *)(current_hit->object))->color->green;
		*(prog->img_pixels + (((y * prog->win_width) + x) * 4) + 2) = ((t_sphere *)(current_hit->object))->color->blue;
		printf("pixel x%d y%d : r%d g%d b%d\n", x, y, ((t_sphere *)(current_hit->object))->color->red, ((t_sphere *)(current_hit->object))->color->green, ((t_sphere *)(current_hit->object))->color->blue);
		//mlx_pixel_put(prog->mlx_ptr, prog->win_ptr, x, y, color(((t_sphere *)(current_hit->object))->color));
	}
	else
	{
		*(prog->img_pixels + ((y * prog->win_width) + x) * 4) = 0;
		*(prog->img_pixels + ((y * prog->win_width) + x + 1) * 4) = 0;
		*(prog->img_pixels + ((y * prog->win_width) + x + 2) * 4) = 0;
		//mlx_pixel_put(prog->mlx_ptr, prog->win_ptr, x, y, 0);
	}
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
		// A changer pour gérer tous les types d'objets
		//printf("obj->pos->z : %f\n",((t_sphere *)(tmp->object))->pos->z);
		new_dist = intersect_sphere(ray, (t_sphere *)(tmp->object));
		//printf("new_dist : %f\n", new_dist);
		if (new_dist < dist && new_dist != -1.0)
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

	printf("----------------\n");
	printf("INITIALIZING\n");
	x = 0;
	y = 0;
	init_img(prog);
	compute_camera_projection(prog);
	printf("win_width : %i / win_height : %i\n", prog->win_width, prog->win_height);
	printf("prog->lower_left_corner : ");
	print_vec3(prog->lower_left_corner);
	printf("prog->horizontal : ");
	print_vec3(prog->horizontal);
	printf("prog->vertical : ");
	print_vec3(prog->vertical);
	printf("----------------\n");
	while (y < prog->win_height) // Pour chaque ligne
	{
		while (x < prog->win_width) // Pour chaque pixel dans cette ligne
		{	
			//printf("----------------\n");
			//printf("x : %i / y : %i\n", x, y);
			ray = get_ray(x, y, prog);
			printf("ray->dir->x : %f / ray->dir->y : %f / ray->dir->z : %f\n", ray->dir->x, ray->dir->y, ray->dir->z);
			current_hit = collide_ray(ray,prog);
			free_ray(ray);
			ray = NULL;
			x++;
			test_color(x, y, current_hit, prog);
		}
		y++;
		x = 0;
	}
	printf("DONE\n");
	mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_ptr, 0, 0);
	printf("DONE 2\n");
	mlx_destroy_image(prog->mlx_ptr, prog->img_ptr);
}


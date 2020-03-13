/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/07 14:42:55 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/13 16:48:03 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int		color(t_color *color)
{
	return ((color->red << 16) + (color->green << 8) + color->blue);
}

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

	// Définition rapide de la caméra (A ENLEVER)
	// Supposons que la caméra soit au centre (0,0,0) et orientée vers +z (0,0,1) ?.
	int		fov = 90;
	double	theta = (double)(fov)*PI/180.0;
	double	half_width = (double)(tan(theta/2));
	double	ratio = ((double)(prog->win_width))/((double)(prog->win_height));
	double	half_height = ratio * half_width;
	t_vec3	*lower_left_corner;
	t_vec3	*horizontal;
	t_vec3	*vertical;
	t_vec3	*cam_origin;
	lower_left_corner = new_vec3(-half_width, -half_height, -1.0);
	horizontal = new_vec3(2 * half_width, 0.0, 0.0);
	vertical = new_vec3(0.0, 2 * half_height, 0.0);
	printf("----------------\n");
	printf("INITIALIZING\n");
	printf("win_width : %i / win_height : %i\n", prog->win_width, prog->win_height);
	printf("theta : %f\n", theta);
	printf("half_width : %f\n", half_width);
	printf("ratio : %f\n", ratio);
	printf("half_height : %f\n", half_height);
	printf("----------------\n");
	
	double u;
	double v;
	double dir_x;
	double dir_y;
	double dir_z;
	t_vec3 *direction;

	x = 0;
	y = 0;

	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	img_ptr = mlx_new_image(prog->mlx_ptr, prog->win_width, prog->win_height);
	prog->img_ptr = img_ptr;
	prog->img_pixels = mlx_get_data_addr(prog->img_ptr, &bits_per_pixel, &size_line, &endian);	

	while (y < prog->win_height) // Pour chaque ligne
	{
		while (x < prog->win_width) // Pour chaque pixel dans cette ligne
		{	
			//printf("----------------\n");
			//printf("x : %i / y : %i\n", x, y);
			u = ((double)(x))/((double)(prog->win_width));
			v = ((double)(y))/((double)(prog->win_height));
			//printf("u : %f / v : %f\n", u, v);
			cam_origin = new_vec3(0.0,0.0,0.0);
			dir_x = lower_left_corner->x + u * horizontal->x + v * vertical->x - cam_origin->x;
			dir_y = lower_left_corner->y + u * horizontal->y + v * vertical->y - cam_origin->y;
			dir_z = lower_left_corner->z + u * horizontal->z + v * vertical->z - cam_origin->z;
			direction = new_vec3(dir_x, dir_y, dir_z);
			//printf("dir_x : %f / dir_y : %f / dir_z : %f\n", dir_x, dir_y, dir_z);
			ray = new_ray(cam_origin, direction);
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


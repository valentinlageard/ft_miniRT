/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:07:26 by vlageard          #+#    #+#             */
/*   Updated: 2020/06/16 19:40:33 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	free_scene(t_prog *prog)
{
	free_cyls(prog->cylinders);
	free_squares(prog->squares);
	free_triangles(prog->triangles);
	free_planes(prog->planes);
	free_spheres(prog->spheres);
	free_objects(prog->objects);
	free_lights(prog->lights);
	free_cams(prog->cams);
	free(prog->ambient_color);
}

void	quit(t_prog *prog)
{
	free_scene(prog);
	mlx_clear_window(prog->mlx_ptr, prog->win_ptr);
	mlx_destroy_window(prog->mlx_ptr, prog->win_ptr);
	free(prog->mlx_ptr);
	free(prog);
	exit(0);
}
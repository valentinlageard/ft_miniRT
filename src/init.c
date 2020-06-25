/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:48:12 by vlageard          #+#    #+#             */
/*   Updated: 2020/06/25 15:58:59 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_prog	*init_prog(void)
{
	t_prog	*prog;

	if (!(prog = malloc(sizeof(t_prog))))
		return (NULL);
	prog->mlx_ptr = mlx_init();
	prog->win_ptr = NULL;
	prog->win_width = 0;
	prog->win_height = 0;
	prog->img_ptr = NULL;
	prog->img_pixels = NULL;
	prog->export = 0;
	prog->cams = NULL;
	prog->current_cam = NULL;
	prog->half_height = 0.0;
	prog->half_width = 0.0;
	prog->ambient_intensity = 0.0;
	prog->ambient_color = NULL;
	prog->lights = NULL;
	prog->objects = NULL;
	prog->spheres = NULL;
	prog->planes = NULL;
	prog->triangles = NULL;
	prog->squares = NULL;
	prog->cylinders = NULL;
	prog->name = NULL;
	return(prog);
}

void	init_win(int width, int height, t_prog *prog)
{
	prog->win_width = width;
	prog->win_height = height;
	prog->win_ptr = mlx_new_window(prog->mlx_ptr, width, height, "miniRT");
}
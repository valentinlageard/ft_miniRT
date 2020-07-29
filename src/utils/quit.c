/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 19:07:26 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/24 19:42:37 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	free(prog->name);
}

void	quit(t_prog *prog)
{
	free_scene(prog);
	if (prog->win_ptr)
	{
		mlx_clear_window(prog->mlx_ptr, prog->win_ptr);
		mlx_destroy_window(prog->mlx_ptr, prog->win_ptr);
	}
	free(prog->mlx_ptr);
	free(prog);
	exit(EXIT_SUCCESS);
}

void	pcustomerror(int errnum)
{
	ft_printf("Error\n");
	if (errnum == -1)
		ft_printf("Filename error\n");
	if (errnum == -2)
		ft_printf("Configuration file error\n");
}

void	error_quit(t_prog *prog, int errnum)
{
	if (errnum > 0)
		perror("Error\n");
	else
		pcustomerror(errnum);
	free_scene(prog);
	if (prog->win_ptr)
	{
		mlx_clear_window(prog->mlx_ptr, prog->win_ptr);
		mlx_destroy_window(prog->mlx_ptr, prog->win_ptr);
	}
	free(prog->mlx_ptr);
	free(prog);
	exit(EXIT_FAILURE);
}

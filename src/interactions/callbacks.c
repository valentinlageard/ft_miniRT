/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:47:53 by vlageard          #+#    #+#             */
/*   Updated: 2020/08/07 17:58:07 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	key_callback(int k, int *param)
{
	if (k == 99)
		change_camera((t_prog *)(param));
	if (k == 65307)
		quit((t_prog *)(param));
	return (0);
}

int	exit_callback(int *param)
{
	quit((t_prog *)param);
	return (0);
}

int	expose_callback(int *param)
{
	t_prog *prog;

	prog = (t_prog *)param;
	if (prog->img_ptr)
		mlx_put_image_to_window(prog->mlx_ptr, prog->win_ptr, prog->img_ptr,
			0, 0);
	ft_printf("Reexpose\n");
	mlx_expose_hook(prog->win_ptr, expose_callback, prog);
	return (0);
}

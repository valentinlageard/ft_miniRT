/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:59:16 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/13 17:00:45 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	init_img(t_prog *prog)
{
	void	*img_ptr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	img_ptr = mlx_new_image(prog->mlx_ptr, prog->win_width, prog->win_height);
	prog->img_ptr = img_ptr;
	prog->img_pixels = mlx_get_data_addr(prog->img_ptr, &bits_per_pixel, &size_line, &endian);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:48:12 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/06 17:48:51 by vlageard         ###   ########.fr       */
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
	prog->cams = NULL;
	return(prog);
}

void	init_win(int width, int height, t_prog *prog)
{
	prog->win_width = width;
	prog->win_height = height;
	prog->win_ptr = mlx_new_window(prog->mlx_ptr, width, height, "miniRT");
}
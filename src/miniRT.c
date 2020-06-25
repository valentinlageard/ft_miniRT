/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:49:02 by vlageard          #+#    #+#             */
/*   Updated: 2020/06/25 16:16:54 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main(int ac, char **av)
{
	t_prog	*prog;

	if (ac >= 2)
	{
		printf("Program initialization\n");
		prog = init_prog();
		parse_name(av[1], prog);
		if (ac == 3)
		{
			if (!ft_strncmp(av[2], "-save", 4))
		 		prog->export = 1;
		}
		// Check .rt
		printf("Parsing\n");
		parse_file(av[1], prog);
		printf("Window initialization\n");
		init_win(prog->win_width, prog->win_height, prog);
		compute_image(prog);
		//mlx_hook(mlx_window, DestroyNotify, StructureNotifyMask, exit_callback, (void *)0);
		mlx_key_hook(prog->win_ptr, key_callback, prog);
		//mlx_mouse_hook(prog->win_ptr, mouse_callback, prog);
		mlx_loop(prog->mlx_ptr);
	}
	if (*av != 0)
		return (0);
	while (1);
	return (0);
}
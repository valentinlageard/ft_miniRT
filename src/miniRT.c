/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:49:02 by vlageard          #+#    #+#             */
/*   Updated: 2020/05/05 19:37:17 by vlageard         ###   ########.fr       */
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
		// Check .rt
		printf("Parsing\n");
		parse_file(av[1], prog);
		printf("Window initialization\n");
		init_win(prog->win_width, prog->win_height, prog);
		compute_image(prog);
		mlx_key_hook(prog->win_ptr, key_callback, prog);
		mlx_loop(prog->mlx_ptr);
	}
	if (*av != 0)
		return (0);
	return (0);
}
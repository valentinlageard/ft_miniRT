/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:49:02 by vlageard          #+#    #+#             */
/*   Updated: 2020/07/24 19:28:03 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int ac, char **av)
{
	t_prog	*prog;

	if (ac >= 2)
	{
		if (!(prog = init_prog()))
		{
			perror("Error\n");
			return (0);
		}
		parse_name(av[1], prog);
		if (ac == 3)
		{
			if (!ft_strncmp(av[2], "-save", 4))
				prog->export = 1;
		}
		parse_file(av[1], prog);
		init_win(prog->win_width, prog->win_height, prog);
		compute_image(prog);
		mlx_hook(prog->win_ptr, 17, 1L << 17, exit_callback, prog);
		mlx_key_hook(prog->win_ptr, key_callback, prog);
		mlx_loop(prog->mlx_ptr);
	}
	return (0);
}

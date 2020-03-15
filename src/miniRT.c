/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 17:49:02 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/14 22:23:02 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int main(int ac, char **av)
{
	t_prog	*prog;

	if (ac >= 2)
	{
		prog = init_prog();
		// Check .rt
		printf("---------------\nPARSING\n");
		parse_file(av[1], prog);
		printf("---------------\n");
		init_win(prog->win_width, prog->win_height, prog);
		compute_image(prog);
		// Compute raytraced image
		// Create window and print image
		// Wait for instructions
	}
	while (1);
	if (*av != 0)
		return (0);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/04 18:47:53 by vlageard          #+#    #+#             */
/*   Updated: 2020/06/16 17:34:26 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int key_callback(int k, int *param)
{
	printf("k : %d\n", k);
	if (k == 99)
		change_camera((t_prog *)(param));
	if (k == 65307)
		quit((t_prog *)(param));
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:03:48 by vlageard          #+#    #+#             */
/*   Updated: 2020/05/21 18:10:12 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_square	*new_sq(void)
{
	t_square	*new_square;
	
	if (!(new_square = (t_square *)malloc(sizeof(t_square))))
		return (NULL);
	new_square->next = NULL;
	return(new_square);
}

void	push_back_square(t_square **first_square, t_square *new_square)
{
	t_square	*tmp;

	if (*first_square == NULL)
		*first_square = new_square;
	else
	{
		tmp = *first_square;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_square;
	}
}
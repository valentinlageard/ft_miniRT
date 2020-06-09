/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 17:33:15 by vlageard          #+#    #+#             */
/*   Updated: 2020/06/08 17:45:51 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_cyl	*new_cyl(void)
{
	t_cyl	*new_cyl;
	
	if (!(new_cyl = (t_cyl *)malloc(sizeof(t_cyl))))
		return (NULL);
	new_cyl->next = NULL;
	return(new_cyl);
}

void	push_back_cyl(t_cyl **first_cyl, t_cyl *new_cyl)
{
	t_cyl	*tmp;

	if (*first_cyl == NULL)
		*first_cyl = new_cyl;
	else
	{
		tmp = *first_cyl;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_cyl;
	}
}
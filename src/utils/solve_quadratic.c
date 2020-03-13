/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve_quadratic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlageard <vlageard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/13 16:08:12 by vlageard          #+#    #+#             */
/*   Updated: 2020/03/13 16:14:21 by vlageard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

double	get_min_quadratic_solution(double a, double b, double c)
{
	double	solution1;
	double	solution2;

	if ((b * b - 4 * a * c) >= 0)
	{
		solution1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
		solution2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
		return (solution1 <= solution2 ? solution1 : solution2);
	}
	else
		return (-1);
}
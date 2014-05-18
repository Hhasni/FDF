/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iso.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 19:37:36 by hhasni            #+#    #+#             */
/*   Updated: 2014/04/27 19:40:12 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			isometric_proj_y(int x, int y, int z, t_env *e)
{
	y = (int)(((sqrt(2) * -1) / 4) * (sin(-120)) * (x + y)
			+ (cos(120) * -(z * 2)) + (HEIGH / 3) + e->coeff_move_y);
	return (y);
}

int			isometric_proj_x(int x, int y, t_env *e)
{
	x = (int)((sqrt(2) / 4) * (x - y) + (WIDTH / 2.5) + e->coeff_move_x);
	return (x);
}

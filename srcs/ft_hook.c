/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/28 18:39:47 by hhasni            #+#    #+#             */
/*   Updated: 2014/04/27 19:42:08 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				key_hook(int keycode, t_env *e)
{
	if (keycode == 65363)
		e->coeff_move_x += 10;
	if (keycode == 65361)
		e->coeff_move_x -= 10;
	if (keycode == 65364)
		e->coeff_move_y += 10;
	if (keycode == 65362)
		e->coeff_move_y -= 10;
	if (keycode == 61)
		e->coeff_view += 10;
	if (keycode == 45)
		e->coeff_view -= 10;
	if (keycode == 65307)
		exit(0);
	mlx_clear_window(e->mlx, e->win);
	expose_hook(e);
	return (0);
}

int				mouse_hook(void)
{
	return (0);
}

int				expose_hook(t_env *e)
{
	ft_recover_specs(e);
	return (0);
}

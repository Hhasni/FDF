/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bressen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 19:32:21 by hhasni            #+#    #+#             */
/*   Updated: 2014/04/27 19:43:49 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void			ft_bres_back(t_env *e, t_bres b, int color)
{
	b.cumul = b.dx / 2;
	b.i = 1;
	while (b.i <= b.dx)
	{
		b.x += b.xinc;
		b.cumul += b.dy;
		if (b.cumul >= b.dx)
		{
			b.cumul -= b.dx;
			b.y += b.yinc;
		}
		if (color < 9028852)
			color += 100000;
		mlx_pixel_put(e->mlx, e->win, b.x, b.y, color);
		b.i++;
	}
}

static void			ft_bres_front(t_env *e, t_bres b, int color)
{
	b.cumul = b.dy / 2;
	b.i = 1;
	while (b.i <= b.dy)
	{
		b.y += b.yinc;
		b.cumul += b.dx;
		if (b.cumul >= b.dy)
		{
			b.cumul -= b.dy;
			b.x += b.xinc;
		}
		if (color < 9028852)
			color += 100000;
		mlx_pixel_put(e->mlx, e->win, b.x, b.y, color);
		b.i++;
	}
}

static void			bressen(t_env *e, t_specs s, int xf, int yf)
{
	t_bres			b;
	int				color;

	color = 3355443;
	b.x = s.new_x;
	b.y = s.new_y;
	b.dx = xf - s.new_x;
	b.dy = yf - s.new_y;
	if (b.dx > 0)
		b.xinc = 1;
	else
		b.xinc = -1;
	if (b.dy > 0)
		b.yinc = 1;
	else
		b.yinc = -1;
	b.dx = abs(b.dx);
	b.dy = abs(b.dy);
	mlx_pixel_put(e->mlx, e->win, b.x, b.y, color);
	if (b.dx > b.dy)
		ft_bres_back(e, b, color);
	else
		ft_bres_front(e, b, color);
}

void				ft_my_bres_x(t_env *e, t_specs s, int old_z)
{
	int				x;
	int				y;

	x = isometric_proj_x(s.b_old_x, s.y, e);
	y = isometric_proj_y(s.b_old_x, s.y, old_z, e);
	bressen(e, s, x, y);
}

void				ft_my_bres_y(t_env *e, t_specs s, int old_z)
{
	int				x;
	int				y;

	x = isometric_proj_x(s.x, s.b_old_y, e);
	y = isometric_proj_y(s.x, s.b_old_y, old_z, e);
	bressen(e, s, x, y);
}

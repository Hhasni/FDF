/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 19:38:43 by hhasni            #+#    #+#             */
/*   Updated: 2014/04/27 19:39:55 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void			ft_join_lines(t_env *e, int b_old_x, t_specs s, int z)
{
	int			final_x;
	int			b_x;
	int			final_y;

	final_y = 0;
	final_x = 0;
	b_x = s.x;
	while (b_old_x < b_x)
	{
		final_x = isometric_proj_x(b_old_x, s.y, e);
		final_y = isometric_proj_y(b_old_x, s.y, z, e);
		if (z > 0)
			mlx_pixel_put(e->mlx, e->win, final_x, final_y, (z * 30) + 9028852);
		else if (z < 0)
			mlx_pixel_put(e->mlx, e->win, final_x, final_y, (z * 30) + 2271216);
		else
			mlx_pixel_put(e->mlx, e->win, final_x, final_y, (z * 30) + 3355443);
		b_old_x++;
	}
}

void			ft_join_colomns(t_env *e, int b_old_y, t_specs s, int z)
{
	int			final_x;
	int			final_y;
	int			b_y;

	final_y = 0;
	final_x = 0;
	b_y = s.y;
	while (b_old_y < b_y)
	{
		final_x = isometric_proj_x(s.x, b_old_y, e);
		final_y = isometric_proj_y(s.x, b_old_y, z, e);
		if (z > 0)
			mlx_pixel_put(e->mlx, e->win, final_x, final_y, (z * 30) + 9028852);
		else if (z < 0)
			mlx_pixel_put(e->mlx, e->win, final_x, final_y, (z * 30) + 2271216);
		else
			mlx_pixel_put(e->mlx, e->win, final_x, final_y, (z * 30) + 3355443);
		b_old_y++;
	}
}

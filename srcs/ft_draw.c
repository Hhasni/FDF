/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/28 18:40:43 by hhasni            #+#    #+#             */
/*   Updated: 2014/04/27 19:50:09 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void			ft_draw(t_env *e, t_specs specs, int a, int k)
{
	specs.new_x = isometric_proj_x(specs.x, specs.y, e);
	specs.new_y = isometric_proj_y(specs.x, specs.y, specs.my_map[a][k], e);
	if (k > 0)
	{
		if (specs.my_map[a][k - 1] != specs.my_map[a][k])
			ft_my_bres_x(e, specs, specs.my_map[a][k - 1]);
		else
			ft_join_lines(e, specs.b_old_x, specs, specs.my_map[a][k]);
	}
	if (a > 0)
	{
		if (specs.my_map[a - 1][k] != specs.my_map[a][k])
			ft_my_bres_y(e, specs, specs.my_map[a - 1][k]);
		else
			ft_join_colomns(e, specs.b_old_y, specs, specs.my_map[a][k]);
	}
}

void				ft_recover_specs(t_env *e)
{
	t_map			*map;
	t_specs			specs;
	int				k;
	int				a;

	map = NULL;
	a = 0;
	if ((specs.nb_lines = ft_get_map(e->file, &map)) == -1)
		exit (0);
	specs.my_map = ft_to_tab_int(map, specs.nb_lines);
	while (a < specs.nb_lines)
	{
		k = 0;
		specs.x = (WIDTH / map->size_line) + e->coeff_view;
		while (k < map->size_line)
		{
			ft_draw(e, specs, a, k++);
			specs.b_old_x = specs.x;
			specs.x += (WIDTH / map->size_line) + e->coeff_view;
		}
		specs.b_old_y = specs.y;
		specs.y += (HEIGH / specs.nb_lines) + e->coeff_view;
		a++;
	}
}

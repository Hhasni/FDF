/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/28 16:46:16 by hhasni            #+#    #+#             */
/*   Updated: 2014/04/27 19:36:50 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int				main(int ac, char **av)
{
	t_env		e;

	if (ac == 2)
	{
		e.file = av[1];
		e.mlx = mlx_init();
		e.win = mlx_new_window(e.mlx, WIDTH, HEIGH, "FDF");
		mlx_key_hook(e.win, key_hook, &e);
		mlx_expose_hook(e.win, expose_hook, &e);
		mlx_mouse_hook(e.win, mouse_hook, &e);
		mlx_loop(e.mlx);
	}
	return (0);
}

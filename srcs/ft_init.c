/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/27 19:40:21 by hhasni            #+#    #+#             */
/*   Updated: 2014/04/27 19:40:58 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static int			ft_tablen(char **tab)
{
	int				i;

	i = 0;
	if (tab)
	{
		while (tab[i])
			i++;
		return (i);
	}
	return (0);
}

static int			ft_count(char *str)
{
	char			**new;
	int				i;

	i = 0;
	new = NULL;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && (str[i] != ' ' && str[i] != '-'))
			exit(0);
		i++;
	}
	new = ft_strsplit(str, ' ');
	return (ft_tablen(new));
}

int					ft_get_map(char *file, t_map **map)
{
	int				fd;
	char			*line;
	int				l;

	l = 0;
	line = NULL;
	if ((fd = open(file, O_RDONLY | S_IRUSR)) == -1)
	{
		write(1, "open_error\n", ft_strlen("open_error\n"));
		return (-1);
	}
	while (get_next_line(fd, &line) == 1)
	{
		l++;
		ft_fill_map_specs(map, line, l, ft_count(line));
	}
	if (close(fd) == -1)
	{
		write(1, "close_error\n", ft_strlen("close_error\n"));
		return (-1);
	}
	return (l);
}

int					**ft_to_tab_int(t_map *map, int nb_l)
{
	int				**map_tab;
	char			**tmp_tab;
	int				i;
	int				l;

	i = 0;
	l = 0;
	if (!(map_tab = (int **)malloc(sizeof(int *) * nb_l)))
		return (NULL);
	while (i < nb_l)
	{
		if (!(map_tab[i] = (int *)malloc(sizeof(int) * map->size_line)))
			return (NULL);
		i++;
	}
	while (map)
	{
		i = -1;
		tmp_tab = ft_strsplit(map->line, ' ');
		while (tmp_tab[++i])
			map_tab[l][i] = ft_atoi(tmp_tab[i]);
		l++;
		map = map->next;
	}
	return (map_tab);
}

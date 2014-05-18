/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/15 23:03:25 by hhasni            #+#    #+#             */
/*   Updated: 2014/04/16 09:57:49 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void		ft_fill_map_specs(t_map **map, char *line, int i, int size)
{
	t_map	*tmp;
	t_map	*new;

	tmp = NULL;
	new = NULL;
	if (!(new = malloc(sizeof(t_map))))
		return ;
	new->line = ft_strdup(line);
	new->nb_line = i;
	new->size_line = size;
	new->next = NULL;
	tmp = *map;
	if (tmp == NULL)
		*map = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

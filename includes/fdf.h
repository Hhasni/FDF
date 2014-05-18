/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhasni <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/28 16:47:40 by hhasni            #+#    #+#             */
/*   Updated: 2014/04/27 19:49:38 by hhasni           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define BUFF_SIZE 100
# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include <fcntl.h>
# include <math.h>
# define HEIGH 1076
# define WIDTH 2024

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	char			*file;
	int				coeff_view;
	int				coeff_move_y;
	int				coeff_move_x;
}					t_env;

typedef struct		s_map
{
	char			*line;
	int				nb_line;
	int				size_line;
	struct s_map	*next;
}					t_map;

typedef struct		s_bre
{
	int				dx;
	int				dy;
	int				i;
	int				xinc;
	int				yinc;
	int				cumul;
	int				x;
	int				y;
}					t_bres;

typedef struct		s_specs
{
	int				nb_lines;
	int				nb_int;
	int				**my_map;
	int				x;
	int				y;
	int				new_x;
	int				new_y;
	int				b_old_x;
	int				b_old_y;
	int				color;
}					t_specs;

int					get_next_line(int const fd, char **line);
int					expose_hook(t_env *e);
int					mouse_hook(void);
int					key_hook(int keycode, t_env *e);
void				ft_recover_specs(t_env *e);
void				*ft_memalloc(int size);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strdup(char *s1);
int					ft_strlen(char *s);
void				ft_fill_map_specs(t_map **map, char *line, int i, int size);
char				**ft_strsplit(char *str, char c);
int					ft_atoi(const char *str);
void				ft_my_bres_y(t_env *e, t_specs s, int old_z);
void				ft_my_bres_x(t_env *e, t_specs s, int old_z);
int					isometric_proj_x(int x, int y, t_env *e);
int					isometric_proj_y(int x, int y, int z, t_env *e);
int					ft_get_map(char *file, t_map **map);
int					**ft_to_tab_int(t_map *map, int nb_l);
void				ft_join_lines(t_env *e, int b_old_x, t_specs s, int z);
void				ft_join_colomns(t_env *e, int b_old_y, t_specs s, int z);
#endif

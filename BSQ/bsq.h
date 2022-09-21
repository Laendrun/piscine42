/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 18:58:29 by saeby             #+#    #+#             */
/*   Updated: 2022/09/21 12:12:51 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

struct	s_map_info
{
	int		lines;
	int		cols;
	int		f_size;
	char	empt;
	char	obst;
	char	full;
};
typedef struct s_map_info	t_mapi;

struct	s_square
{
	int	x;
	int	y;
	int	size;
};
typedef struct s_square		t_square;

// main.c
int			bsq(char *map_file);
int			stdin_map(void);
int			clear_map(char *map_file);

// ft_write.c
void		ft_putchar(char c);
void		ft_putstr(char *s);

// map.c
t_mapi		get_map_info(char *map_file);

// map_helper.c
int			fill_map_infos(int f_desc, t_mapi *map_infos);
int			get_line_count(char *map_infos_buf);
char		get_empt_char(char *map_infos_buf);
char		get_obst_char(char *map_infos_buf, t_mapi *map_infos);
char		get_full_char(char *map_infos_buf, t_mapi *map_infos);

// map_helper2.c
void		fill_infos_buffer(char *buffer, int f_desc);
int			get_col_count(char *map_buf);
char		**create_table(int x, int y);

// file_helper.c
int			file_size(int f_desc);
void		fill_map_buffer(char *buffer, char *map_file);
char		**ft_split(char *str, t_mapi *map_info);
int			fill_table(char *str, char **table, t_mapi *map_info, int c[3]);

// errors.c
int			map_error(void);

// check.c
int			char_is_num(char c);

// conversion.c
int			ft_atoi(char *str);

//display.c
void		print_map(char **map, t_mapi *map_info);

//squarefinder.c
int			possible_square(char **map, t_square square,
				int sizemax, t_mapi *mapi);
t_square	find_biggest_square(char **map, int map_size, t_mapi *map_info);
void		mark_biggest_square(char **map, t_square bigsquare, t_mapi *mapi);

#endif

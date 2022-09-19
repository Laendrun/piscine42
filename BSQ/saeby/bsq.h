/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:43:53 by saeby             #+#    #+#             */
/*   Updated: 2022/09/19 13:38:32 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

typedef struct s_map_info
{
	int		lines;
	char	empt;
	char	obst;
	char	full;
} t_mapi;

// ft_write.c
void	ft_putchar(char c);
void	ft_putstr(char *s);

// map_helper.c
t_mapi	get_map_info(char *map_file);
void	fill_map_infos(int f_desc, t_mapi *map_infos);
int		get_line_count(char *map_infos_buf);

// errors.c
int		map_error(void);

// check.c
int		char_is_num(char c);

// conversion.c
int		ft_atoi(char *str);

#endif

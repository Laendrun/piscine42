/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 11:43:53 by saeby             #+#    #+#             */
/*   Updated: 2022/09/19 12:04:12 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

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

// errors.c
int		map_error(void);

#endif

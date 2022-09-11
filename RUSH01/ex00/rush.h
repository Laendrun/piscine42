/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:45:48 by saeby             #+#    #+#             */
/*   Updated: 2022/09/11 19:57:53 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		**create_table(int size);
int		size_of_map(char *rules);
void	fill_table(int **table, int *rules_input, int size);
void	print_table(int **table, int size, int mode);
void	init_table(int **table, int size, int value);
void	fill_rules(int **table, int *rules_input, int size);
void	fill_body(int **table, int size);
void	fill_body_strong(int **table, int size);
void	fill_body_strong(int **table, int size);
void	fill_body_strong_top(int **table, int size);
void	fill_body_strong_bottom(int **table, int size);
void	fill_body_strong_right(int **table, int size);
void	fill_body_strong_left(int **table, int size);
void	fill_number_strong(int **table, int size, int number);
void	fill_body_weak(int **table, int size);
void	block_line_col(int *potential_place, int i, int j, int size);
int		*get_rules(char *rules, int size);
int		check_params(int argc);
int		check_rules_format(char *rules);
int		check_rules_content(int *rules_input, int size);
int		ft_is_numeric(char str);
void	ft_putstr(char *str);
void	ft_putchar(char c);
void	ft_print_error(void);

#endif

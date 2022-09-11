/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:20:57 by saeby             #+#    #+#             */
/*   Updated: 2022/09/10 20:16:57 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	ft_print_error(void)
{
	ft_putstr("Error\n");
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_puttable_debug(int **table, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= (size + 2))
	{
		while (j <= (size + 2))
		{
			ft_putchar(table[i][j] + '0');
			ft_putchar(' ');
			j++;
		}
		j = 0;
		ft_putchar('\n');
		i++;
	}
}

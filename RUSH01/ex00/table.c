/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   table.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:23:46 by saeby             #+#    #+#             */
/*   Updated: 2022/09/11 14:17:09 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	**create_table(int size)
{
	int	**cols;
	int	i;

	i = 0;
	cols = malloc((size + 2) * sizeof(int *));
	while (i < (size + 2))
	{
		cols[i] = malloc((size + 2) * sizeof(int *));
		i++;
	}
	return (cols);
}

void	init_table(int **table, int size, int value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < (size + 2))
	{
		while (j < (size + 2))
		{
			table[i][j] = value;
			j++;
		}
		j = 0;
		i++;
	}
}

void	print_table(int **table, int size, int mode)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (mode)
	{
		while (i < (size + 2))
		{
			while (j < (size + 2))
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
	else
	{
		while ((i + 1) < (size + 1))
		{
			while ((j + 1) < (size + 1))
			{
				ft_putchar(table[i + 1][j + 1] + '0');
				ft_putchar(' ');
				j++;
			}
			j = 0;
			ft_putchar('\n');
			i++;
		}
	}
}

int	size_of_map(char *rules)
{
	int	size;
	int	i;

	if (!(check_rules_format(rules)))
	{
		ft_print_error();
		return (0);
	}
	i = 0;
	size = 0;
	while (rules[i] != 0)
	{
		if (!(rules[i] == ' '))
			size++;
		i++;
	}
	if ((size >= 4 * 4) && (size <= 9 * 4))
		return (size / 4);
	ft_print_error();
	return (0);
}

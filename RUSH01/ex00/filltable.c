/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filltable.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:29:09 by ybensegh          #+#    #+#             */
/*   Updated: 2022/09/11 20:57:53 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	fill_table(int **table, int *rules_input, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	init_table(table, size, '.' - '0');
	fill_rules(table, rules_input, size);
	fill_body(table, size);
}
void	fill_top(int **table, int *rules_input, int size)
{
	int	i;

	i = 0;
	while (i + 1 <= size)
	{
		table[0][i + 1] = rules_input[i];
		i++;
	}
}

void	fill_bottom(int **table, int *rules_input, int size)
{
	int	i;

	i = 0;
	while (i + 1 <= size)
	{
		table[size + 1][i + 1] = rules_input[i + size];
		i++;
	}
}

void	fill_left(int **table, int *rules_input, int size)
{
	int	i;

	i = 0;
	while (i + 1 <= size)
	{
		table[i + 1][0] = rules_input[i + (size * 2)];
		i++;
	}	
}

void	fill_right(int **table, int *rules_input, int size)
{
	int	i;

	i = 0;
	while (i + 1 <= size)
	{
		table[i + 1][size + 1] = rules_input[i + (size * 3)];
		i++;
	}	
}

void	fill_rules(int **table, int *rules_input, int size)
{
	fill_top(table, rules_input, size);
	fill_bottom(table, rules_input, size);
	fill_left(table, rules_input, size);
	fill_right(table, rules_input, size);
}

void	fill_body_strong_top(int **table, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= size)
	{
		if (table[0][i] == 1)
			table[1][i] = size;
		if (table[0][i] == size)
		{
			while (j < size)
			{
				table[j + 1][i] = j + 1;
				j++;
			}
		}
		i++;
	}
}

void	fill_body_strong_bottom(int **table, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size;
	while (i <= size)
	{
		if (table[size + 1][i] == 1)
			table[size][i] = size;
		if (table[size + 1][i] == size)
		{
			while (j > 0)
			{
				table[j][i] = size - (j - 1);
				j--;
			}
		}
		i++;
	}
}

void	fill_body_strong_left(int **table, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= size)
	{
		if (table[i][0] == 1)
			table[i][1] = size;
		if (table[i][0] == size)
		{
			while (j < size)
			{
				table[i][j + 1] = j + 1;
				j++;
			}
		}
		i++;
	}
}

void	fill_body_strong_right(int **table, int size)
{
	int	i;
	int	j;

	i = 0;
	j = size;
	while (i <= size)
	{
		if (table[i][size + 1] == 1)
			table[i][size] = size;
		if (table[i][size + 1] == size)
		{
			while (j > 0)
			{
				table[i][j] = size - (j - 1);
				j--;
			}
		}
		i++;
	}
}

void	fill_body_strong(int **table, int size)
{
	int	i;

	i = size;
	fill_body_strong_top(table, size);
	fill_body_strong_bottom(table, size);
	fill_body_strong_left(table, size);
	fill_body_strong_right(table, size);
	print_table(table, size, 1);
	ft_putchar('\n');
	while (i > 0)
	{
		fill_number_strong(table, size, i);
		i--;
	}
}

void	fill_number_strong(int **table, int size, int number)
{
	int *potential_place;
	int	i;
	int	j;
	int	k;
	int	sum;
	int	x;
	int	y;

	x = -1;
	y = -1;
	i = 0;
	j = 0;
	sum = 0;
	k = size;
	potential_place = malloc(((size * 2) * (sizeof(int))));
	while (i < size * 2)
	{
		potential_place[i] = 1;
		i++;
	}
	i = 0;
	while (k > 0)
	{
		while (i < size)
		{
			while (j < size)
			{
		//	printf("k: %d table[%d][%d] : %d\n", k, i + 1, j + 1, table[i + 1][j + 1]);
				if(table[i + 1][j + 1] == number)
				{
					block_line_col(potential_place, i+1, j+1, size);
				}
				j++;
			}
			j = 0;
			i++;
		}
		k--;
		i = 0;
	}
	i = 0;

	while (i < size * 2)
	{
		sum = 0;
		if (potential_place[i] == 1)
		{
			if (x == -1)
				x = i + 1;
			sum++;
		}

		if (potential_place[i + size] == 1)
		{
			if (y == -1)
				y = i + size - 2;
			sum++;
		}
		if (sum == 2)
		{
			if (table[y][x] == ('.'-48))
				table[y][x] = number;
		}
		i++;
	}
	//printf("sum %d", sum);
	free(potential_place);
}
/*
 * table[line][col]
 */
void	block_line_col(int *potential_place, int i, int j, int size)
{
	(void) size;
	potential_place[j] = 0;
	potential_place[i + 2 + size] = 0;	
}

void	fill_body(int **table, int size)
{
	int i ;

	i = 0;
	while (i < 2) 	
	{
		fill_body_strong(table, size);
		fill_body_weak(table, size);
		i++;
	}
}

void	fill_body_weak(int **table, int size)
{
	int	i;
	int	j;
	int	k;
	int	l;
	int	*possible_values;
	int	found;
	int number;
	int *target;

	printf("bodyweak\n");

	possible_values = malloc(size * sizeof(int));
	
	found = 0;
	i = 0;
	while (i < size)
	{
		possible_values[i] = i + 1;
		i++;
	}

	i = 1;
	j = 1;
	k = 1;
	l = 0;
	while (i < size + 1 && !found)
	{
		while (j < size + 1 && !found)
		{
		
			if (table[j][i] == ('.' - 48))
			{
				found = 1;
				target = &table[i][j];
				while (k < size + 1)
				{
					while (l < size)
					{
						if (table[j][k] == possible_values[l])
						{
							//printf("table[%d][%d] : %d\n", j, i, table[j][i]);
							possible_values[l] = 0;

						}
						l++;
					}
					l = 0;
					k++;
				}
			}
			l = 0;
			k = 1;
			j++;
		}
		l = 0;
		k = 1;
		j = 1;
		i++;
	}
	found = 0;
	i = 0;
	number = 0;
	while (i < size)
	{
		if(number < possible_values[i])
			number = possible_values[i];
		i++;
	}
	*target = number;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 16:01:30 by saeby             #+#    #+#             */
/*   Updated: 2022/09/20 20:20:57 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	fill_infos_buffer(char *buf, int f_desc)
{
	int	i;
	int	br;

	i = 0;
	br = 1;
	while (br != 0)
	{
		br = read(f_desc, &buf[i], 1);
		if (buf[i] == '\n')
		{
			buf[i] = 0;
			br = 0;
		}
		i++;
	}
}

int	get_col_count(char *map_buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map_buf[i] != '\n')
		i++;
		i++;
	while (map_buf[i++] != '\n')
		j++;
	return (j);
}

char	**create_table(int x, int y)
{
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	tmp = malloc((y + 1) * sizeof(char *) * 1000);
	while (i < y + 1)
	{
		tmp[i] = malloc((x + 1) * sizeof(char) * 1000);
		i++;
	}
	i = 0;
	while (i < y + 1)
	{
		j = 0;
		while (j < x + 1)
		{
			tmp[i][j] = 0;
			j++;
		}
		i++;
	}
	return (tmp);
}

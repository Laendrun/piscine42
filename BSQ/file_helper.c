/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:56:16 by saeby             #+#    #+#             */
/*   Updated: 2022/09/21 00:15:51 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	file_size(int f_desc)
{
	char	t;
	int		br;
	int		byte_count;

	byte_count = 0;
	br = 1;
	while (br != 0)
	{
		br = read(f_desc, &t, 1);
		byte_count++;
	}
	return (byte_count);
}

void	fill_map_buffer(char *buf, char *map_file)
{
	int	f_map;
	int	br;
	int	i;

	f_map = open(map_file, O_RDONLY);
	br = 1;
	i = 0;
	while (br != 0)
	{
		br = read(f_map, &buf[i], 1);
		i++;
	}
}

/* c[0] => lines
 * c[1] => column index on each line
 * c[2] => char index in table
 */

char	**ft_split(char *str, t_mapi *map_info)
{
	char	**tmp;
	int		c[3];

	tmp = create_table(map_info->cols, map_info->lines);
	c[1] = 0;
	c[0] = -1;
	while (c[0] < map_info->lines)
	{
		c[2] = 0;
		while (str[c[1]] != '\n')
		{
			if (c[0] >= 0)
			{
				if (fill_table(str, tmp, map_info, c) != 0)
					return (tmp);
			}
			c[1]++;
			c[2]++;
		}
		c[1]++;
		c[0]++;
	}
	return (tmp);
}

int	fill_table(char *str, char **table, t_mapi *map_info, int c[3])
{
	if (str[c[1]] == map_info->empt || str[c[1]] == map_info->obst)
		table[c[0]][c[2]] = str[c[1]];
	else
	{
		table[0][0] = 0;
		return (-1);
	}
	return (0);
}

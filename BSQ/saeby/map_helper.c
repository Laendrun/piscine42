/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:01:21 by saeby             #+#    #+#             */
/*   Updated: 2022/09/19 13:39:07 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_mapi	get_map_info(char *map_file)
{
	(void) map_file;
	int		f_map;
	t_mapi	map_infos;

	map_infos.empt = '2';
	f_map = open(map_file, O_RDONLY);
	if (f_map == -1)
		map_infos.empt = '\0';
	//printf("%s\n", map_info(f_map));
	fill_map_infos(f_map, &map_infos);
	return (map_infos);
}


void	fill_map_infos(int f_desc, t_mapi *map_infos)
{
	char	*buffer;
	int		i;
	int		br;
	(void) map_infos;

	buffer = malloc(100 * sizeof(char));
	i = 0;
	br = 1;
	while (br != 0)
	{
		br = read(f_desc, &buffer[i], 1);
		if (buffer[i] == '\n')
		{
			buffer[i] = 0;
			br = 0;
		}
		i++;
	}
	map_infos->lines = get_line_count(buffer);
	//printf("%d\n", map_infos.lines);
	//printf("Bruh: %s\n", buffer);
}

int	get_line_count(char *map_infos_buf)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (char_is_num(map_infos_buf[i]))
		i++;
	tmp = malloc((i + 1) * sizeof(char));
	j = 0;
	while (j < i)
	{
		tmp[j] = map_infos_buf[j];
		j++;
	}
	tmp[j] = 0;
	i = ft_atoi(tmp);
	free(tmp);
	return (i);
}

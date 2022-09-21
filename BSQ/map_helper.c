/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:01:21 by saeby             #+#    #+#             */
/*   Updated: 2022/09/20 23:08:04 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	fill_map_infos(int f_desc, t_mapi *map_infos)
{
	char	*buffer;

	buffer = malloc(100 * sizeof(char));
	fill_infos_buffer(buffer, f_desc);
	map_infos->f_size = file_size(f_desc);
	map_infos->lines = get_line_count(buffer);
	map_infos->empt = get_empt_char(buffer);
	map_infos->obst = get_obst_char(buffer, map_infos);
	map_infos->full = get_full_char(buffer, map_infos);
	if (map_infos->empt == -1 || map_infos->lines == -1
		|| map_infos->obst == -1 || map_infos->full == -1)
		return (-1);
	return (0);
}

int	get_line_count(char *buf)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (char_is_num(buf[i]))
		i++;
	tmp = malloc((i + 1) * sizeof(char));
	j = 0;
	while (j < i)
	{
		tmp[j] = buf[j];
		j++;
	}
	tmp[j] = 0;
	i = ft_atoi(tmp);
	free(tmp);
	return (i);
}

char	get_empt_char(char *buf)
{
	int	i;

	i = 0;
	while (char_is_num(buf[i]))
		i++;
	if (buf[i] == '\n' || buf[i] == 0)
		return (-1);
	return (buf[i]);
}

char	get_obst_char(char *buf, t_mapi *map_infos)
{
	int	i;

	i = 0;
	while (char_is_num(buf[i]))
		i++;
	if (buf[i + 1] == '\n' || buf[i + 1] == 0 || buf[i + 1] == map_infos->empt)
		return (-1);
	return (buf[i + 1]);
}

char	get_full_char(char *buf, t_mapi *map_infos)
{
	int	i;

	i = 0;
	while (char_is_num(buf[i]))
		i++;
	if (buf[i + 2] == '\n' || buf[i + 2] == 0 || buf[i + 2] == map_infos->empt
		|| buf[i + 2] == map_infos->obst)
		return (-1);
	return (buf[i + 2]);
}

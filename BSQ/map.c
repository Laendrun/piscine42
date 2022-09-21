/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 13:57:02 by saeby             #+#    #+#             */
/*   Updated: 2022/09/21 00:09:14 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_mapi	get_map_info(char *map_file)
{
	int		f_map;
	t_mapi	map_infos;

	map_infos.empt = '1';
	f_map = open(map_file, O_RDONLY);
	if (f_map == -1)
	{
		map_infos.empt = 0;
		return (map_infos);
	}
	if (fill_map_infos(f_map, &map_infos) == -1)
	{
		map_infos.empt = 0;
		return (map_infos);
	}
	return (map_infos);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 12:01:21 by saeby             #+#    #+#             */
/*   Updated: 2022/09/19 12:08:28 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

t_mapi	get_map_info(char *map_file)
{
	int		f_map;
	t_mapi	map_infos;

	f_map = open(map_file, O_RDONLY);
	if (f_map == -1)
	{
		map_infos.empt = '\0';
		return (NULL);
	}
}

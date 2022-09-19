/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:59:10 by saeby             #+#    #+#             */
/*   Updated: 2022/09/19 13:37:05 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int ac, char **av)
{
	t_mapi map_info;
	
	if (ac == 2)
	{
		map_info = get_map_info(av[1]);
		if (map_info.empt == 0)
			return (map_error());
		printf("lines: %d\n", map_info.lines);
	}
	else
	{
		ft_putstr("not yet implemented");
	}
}

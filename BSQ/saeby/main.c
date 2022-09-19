/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 10:59:10 by saeby             #+#    #+#             */
/*   Updated: 2022/09/19 12:05:54 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int ac, char **av)
{
	(void) ac;
	t_mapi map_info;
	
	if (ac == 2)
	{
		map_info = get_map_info(av[1]);
		if (!map_info)
			return (map_error());
		printf("BruhSQ");
	}
	else
	{
		ft_putstr("not yet implemented");
	}
}

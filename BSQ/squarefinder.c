/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squarefinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:18:28 by ybensegh          #+#    #+#             */
/*   Updated: 2022/09/20 23:00:04 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int	possible_square(char **map, t_square square, int sizemax, t_mapi *mapi)
{
	int	ix;
	int	jy;

	if (square.size + square.y > sizemax || square.size + square.x > sizemax)
	{
		return (0);
	}
	jy = square.y;
	while (jy < square.size + square.y)
	{
		ix = square.x;
		while (ix < square.size + square.x)
		{
			if (map[jy][ix] == mapi->obst)
			{
				return (0);
			}	
			ix++;
		}
		jy++;
	}
	return (1);
}

t_square	find_biggest_square(char **map, int map_size, t_mapi *mapi)
{
	t_square	square_max;
	t_square	square_try;

	square_try.size = 0;
	square_try.x = 0;
	square_try.y = 0;
	square_max = square_try;
	square_try.y = 0;
	while (square_try.y < map_size)
	{
		square_try.x = 0;
		while (square_try.x < map_size)
		{
			square_try.size = 0;
			while (possible_square(map, square_try, map_size, mapi))
			{
				if (square_try.size > square_max.size)
					square_max = square_try;
				square_try.size++;
			}
			square_try.x++;
		}
		square_try.y++;
	}
	return (square_max);
}

void	mark_biggest_square(char **map, t_square bigsquare, t_mapi *mapi)
{
	int	ix;
	int	jy;

	jy = bigsquare.y;
	while (jy < bigsquare.size + bigsquare.y)
	{
		ix = bigsquare.x;
		while (ix < bigsquare.size + bigsquare.x)
		{
			map[jy][ix] = mapi->full;
			ix++;
		}
		jy++;
	}
}

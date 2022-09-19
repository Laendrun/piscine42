/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   squarefinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 14:18:28 by ybensegh          #+#    #+#             */
/*   Updated: 2022/09/19 15:17:26 by ybensegh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "bsq.h"

int possible_square(char **map,  int x, int y, int size)
{
	int ix;
	int jy;
	int sizemax = 4 ;

	if (size+y > sizemax || size +x > sizemax )
		return(0);
	jy = y;
	while(jy < size+y)
	{
		ix = x;
		while(ix < size+x) 
		{
			if (map[jy][ix] == 'o')
				return (0);
			ix++;
		}
		jy++;
	}
	return (1);

}


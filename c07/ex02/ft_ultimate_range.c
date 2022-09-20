/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:24:50 by saeby             #+#    #+#             */
/*   Updated: 2022/09/14 13:42:45 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*tmp;

	i = 0;
	if (min >= max)
	{
		*range = 0;
		return (0);
	}
	size = (max - min);
	tmp = malloc(size * 4);
	if (tmp == 0)
		return (-1);
	while (i < size)
	{
		tmp[i] = min + i;
		i++;
	}
	*range = tmp;
	return (size);
}
/*
int	main(void)
{
	int *p_range = 0;
	int min = -10;
	int max = 10;
	printf("%d\n", ft_ultimate_range(&p_range, min, max));
}
*/

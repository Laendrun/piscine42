/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:31:42 by saeby             #+#    #+#             */
/*   Updated: 2022/09/14 13:41:37 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	size;
	int	i;

	range = NULL;
	if (min >= max)
		return (range);
	size = max - min;
	i = 0;
	range = (int *) malloc(size * sizeof(int));
	while (i < size)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}
/*
int	main(void)
{
	int	*ptr;
	int	min;
	int	max;
	int	i;

	i = 0;
	min = -214748364;
	max = 214748364;
	
	ptr = ft_range(min, max);
	while (i < max-min)
	{
		for (int j = 10000; j  >= 0; j++)
			printf("%d\n", ptr[i+j]);
		i++;	
	}
}
*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 05:46:58 by saeby             #+#    #+#             */
/*   Updated: 2022/09/07 11:05:18 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int x;

	x = *a;
	*a = *b;
	*b = x;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	
	i = 0;
	while (i < size - 1)
	{
		//printf("%d\n", i);
		if (tab[i] > tab[i + 1] && i + 1 != size)
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
		{
			i++;	
		}
	}
}
/*
int main(void)
{
	int size = 5;
	int	a[size];
	
	a[0] = 4;
	a[1] = 3;
	a[2] = 2;
	a[3] = 3;
	a[4] = 2;
	printf("Before :\n");
	printf("a[0] %d\n", a[0]);
	printf("a[1] %d\n", a[1]);
	printf("a[2] %d\n", a[2]);
	printf("a[3] %d\n", a[3]);
	printf("a[4] %d\n", a[4]);
	ft_sort_int_tab(a, size);
	printf("After :\n");
	printf("a[0] %d\n", a[0]);
	printf("a[1] %d\n", a[1]);
	printf("a[2] %d\n", a[2]);
	printf("a[3] %d\n", a[3]);
	printf("a[4] %d\n", a[4]);
}
*/

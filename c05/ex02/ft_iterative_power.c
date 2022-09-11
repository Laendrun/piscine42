/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 06:32:48 by saeby             #+#    #+#             */
/*   Updated: 2022/09/06 07:03:08 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	unsigned int	total;

	if (power < 0)
		return (0);
	total = 1;
	while (power != 0)
	{
		total *= nb;
		power--;
	}
	return (total);
}
/*
int main(void)
{
	printf("%d", ft_iterative_power(0, 0));
}
*/

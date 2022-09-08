/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 09:59:03 by saeby             #+#    #+#             */
/*   Updated: 2022/09/07 10:26:10 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb == 0 || nb == 1)
		return (0);
	if (nb > 1)
	{
		while (i >= 2 && i < nb)
		{
			if (nb % i == 0)
				return (0);
			i++;
		}
		return (1);
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	int	i;

	if (nb < 0)
		nb = 0;
	if (nb >= 2147483640)
		return (2147483647);
	i = 0;
	while (!(ft_is_prime(nb + i)))
		i++;
	return (nb + i);
}
/*
int main(void)
{
	printf("%d\n", ft_find_next_prime(222216)); 
}
*/

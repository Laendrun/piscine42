/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 07:03:47 by saeby             #+#    #+#             */
/*   Updated: 2022/09/07 08:06:38 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power != 0 && power >= 0)
		return (nb * (ft_recursive_power(nb, power - 1)));
	else if (power < 0)
		return (0);
	else
		return (1);
}
/*
int	main(void)
{
	printf("%d", ft_recursive_power(-7, 8));
}
*/

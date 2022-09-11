/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb_n.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 14:30:57 by saeby             #+#    #+#             */
/*   Updated: 2022/09/05 00:41:14 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void ft_putchar(char value)
{
	write(1, &value, 1);
}

int ft_pow(int base, int exponent)
{
    // If x^0 return 1
    if (exponent == 0)
        return 1;
    // If we need to find of 0^y
    if (base == 0)
        return 0;
    // For all other cases
    return base * ft_pow(base, exponent - 1);
}

void	ft_putnbr(int nb)
{
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}

void ft_print_comb_n(int n)
{
	ft_putnbr(ft_pow(10, n));
}

int main(void)
{
	ft_print_comb_n(2);
}

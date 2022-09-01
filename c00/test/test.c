/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 02:20:08 by saeby             #+#    #+#             */
/*   Updated: 2022/08/31 23:55:08 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		main(void)
{
	void test(int nb);
	void ft_putchar(char value);
	test(42);
}

void ft_putchar(char value)
{
	write(1, &value, 1);
}

void	test(int nb)
{
		ft_putchar(
}

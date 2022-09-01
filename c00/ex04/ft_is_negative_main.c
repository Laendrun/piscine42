/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 05:06:58 by saeby             #+#    #+#             */
/*   Updated: 2022/08/31 23:23:03 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int main(void)
{
	void ft_is_negative(int n);
	ft_is_negative(1);
	ft_is_negative(-1);
}

void	ft_is_negative(int n)
{
	char	r;

	if (n >= 0)
	{
		r = 'P';
		write(1, &r, 1);
	}
	else
	{
		r = 'N';
		write(1, &r, 1);
	}
}

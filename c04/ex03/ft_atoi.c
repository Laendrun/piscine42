/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:43:14 by saeby             #+#    #+#             */
/*   Updated: 2022/09/04 23:31:07 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char value)
{
	write(1, &value, 1);
}

void	ft_atoi(char *str)
{
	int	i;
	int	s;

	i = 0;
	s = 0;
	while (str[i] >= 9 && str[i] <= 13)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
		{
			s++;
			s = s % 2;
		}
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (s+=2 == 1)
			ft_putchar('-');
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int	main(void)
{
	ft_atoi("	----------------15i48asd");
}

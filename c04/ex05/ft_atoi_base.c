/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 02:51:49 by saeby             #+#    #+#             */
/*   Updated: 2022/09/06 02:54:22 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char value)
{
	write(1, &value, 1);
}

int	ft_posneg(char sign, int s)
{
	if (sign == 45)
		s++;
		s = s % 2;
	return (s);
}

void	ft_atoi(char *str)
{
	int	i;
	int	s;
	int	printed;

	i = 0;
	s = 0;
	printed = 0;
	while (str[i] >= 9 && str[i] <= 13)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		s = ft_posneg(str[i], s);
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (s == 1 && !printed)
			ft_putchar('-');
			printed++;
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

int	main(void)
{
	ft_atoi("	--------------------15i48asd");
}

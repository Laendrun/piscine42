/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 19:43:14 by saeby             #+#    #+#             */
/*   Updated: 2022/09/07 18:14:20 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
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

int	ft_posneg(char sign, int *s)
{
	if (sign == 45)
		*s = *s + 1;
		*s = *s % 2;
	return (*s);
}

int	ft_error(char *str, int *s, int *i)
{
	*i = 0;
	while (str[*i] >= 9 && str[*i] <= 13)
		*i = *i + 1;
	while (str[*i] == 43 || str[*i] == 45)
	{
		*s = ft_posneg(str[*i], s);
		*i = *i + 1;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	value;
	int	i;
	int	j;
	int	k;
	int	s;

	value = 0;
	k = 0;
	if (ft_error(str, &s, &i))
		return (0);
	j = i;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (i > j)
	{
		value += (str[i - 1] - 48) * ft_recursive_power(10, k);
		k++;
		i--;
	}
	if (s)
		value = -value;
	return (value);
}
/*
int	main(void)
{
	char test[] = "\t\t--------1548asd";
	printf("value: %d\n", ft_atoi(test));
}
*/

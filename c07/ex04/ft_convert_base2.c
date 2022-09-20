/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 11:30:55 by saeby             #+#    #+#             */
/*   Updated: 2022/09/14 12:33:51 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_power(int base, int exponent);
int		ft_strlen(char *str);
int		ft_nbr_error(char *nbr, int *s, int *i);
int		ft_base_error(char *base);
int		base10_value(char c, char *base_from);
int		ft_convert_to_b10(char *nbr, char *base_from, int base_type, int *i);
void	ft_convert_to_base_n(int nbr, int base_type, char *response, int *i);
void	ft_fill_response(char *response, char *base_to, char *temp, int *s);
void	*ft_convert_base(char *nbr, char *base_from, char *base_to);

int	ft_power(int base, int exponent)
{
	if (exponent != 0 && exponent >= 0)
		return (base * (ft_power(base, exponent - 1)));
	else if (exponent < 0)
		return (0);
	else
		return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_nbr_error(char *nbr, int *s, int *i)
{
	*i = 0;
	while ((nbr[*i] >= 9 && nbr[*i] <= 13) || nbr[*i] == 32)
		*i = *i + 1;
	while ((nbr[*i] == 43 || nbr[*i] == 45))
	{
		if (nbr[*i] == 45)
			*s = *s + 1;
		*i = *i + 1;
	}
	*i = *i - 1;
	if ((nbr[*i] < 9 || nbr[*i] > 13) && nbr[*i] != 32
		&& nbr[*i] != 43 && nbr[*i] != 45)
		return (1);
	return (0);
}

int	ft_base_error(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (1);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (1);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	base10_value(char c, char *base_from)
{
	int	i;

	i = 0;
	while (base_from[i] != c)
		i++;
	return (i);
}

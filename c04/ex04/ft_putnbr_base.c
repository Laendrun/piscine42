/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:29:12 by saeby             #+#    #+#             */
/*   Updated: 2022/09/07 18:45:11 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i_str;
	unsigned int	j;

	i_str = 0;
	j = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i_str] != '\0')
	{
		while (str[i_str + j] == to_find[j] && str[i_str + j] != '\0')
		{
			j++;
			if (to_find[j] == '\0')
				return (str + i_str);
		}
		i_str++;
		j = 0;
	}
	return (0);
}

void	ft_base_transform(int params[2], char base[100], char adr[1000], int *i)
{
	int	v;

	v = params[1] % params[0];
	adr[*i] = base[v];
	*i = *i + 1;
	if (params[1] / params[0] > 0)
	{
		params[1] = params[1] / params[0];
		ft_base_transform(params, base, adr, i);
	}
}

int	ft_is_valid(char *base)
{
	int	x;
	int	i;
	int	j;

	i = 0;
	j = 0;
	x = ft_strlen(base);
	if (base[0] == '\0' || x == 1)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '-' || base[i] == '+')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}	
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	char	base_chars[100];
	char	values[1000];
	int		i;
	int		params[2];

	if (ft_is_valid(base))
	{
		if (nbr < 0)
		{
			nbr *= -1;
			write(1, "-", 1);
		}
		i = 0;
		params[0] = -1;
		params[1] = nbr;
		while (base[++params[0]] != '\0')
			base_chars[params[0]] = base[params[0]];
		ft_base_transform(params, base_chars, values, &i);
		while (i-- >= 0)
			write(1, &values[i], 1);
		write(1, "\n", 1);
	}
}

int main(void)
{
	char base[] = "0X2Z4567";
	int nbr = 14;
	ft_putnbr_base(nbr, base);
}


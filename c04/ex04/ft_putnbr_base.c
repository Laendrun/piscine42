/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:29:12 by saeby             #+#    #+#             */
/*   Updated: 2022/09/05 23:12:03 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i_str;
	unsigned int	j;

	i_str = 0;
	j = 0;
	if (to_find[0] == '\0')
	{
		return (str);
	}
	while (str[i_str] != '\0')
	{
		while (str[i_str + j] == to_find[j] && str[i_str + j] != '\0')
		{
			j++;
			if (to_find[j] == '\0')
			{
				return (str + i_str);
			}
		}
		i_str++;
		j = 0;
	}
	return (0);
}

void	ft_base_transform(int nbr, int base_type, char base[100], char adr[1000], int *i)
{
	int v;

	v = nbr % base_type;
	adr[*i] = base[v];
	*i = *i + 1;
	if (nbr / base_type > 0)
	{
		ft_base_transform(nbr / base_type, base_type, base, adr, i);
	}
}

int ft_pow(int base, int exponent)
{
	if (exponent == 0)
		return 1;
	if (base == 0)
		return 0;
	return base * ft_pow(base, exponent - 1);
}


void	ft_putnbr_base(int nbr, char *base)
{

	int base_type;
	char base_chars[100];
	char values[1000];
	int i;

	i = 0;
	base_type = 0;

	while (base[base_type] != '\0')
	{
		base_chars[base_type] = base[base_type];
		base_type++;
	}
	//char a = 'a';
	//printf("%s", ft_strstr(&base_chars[1], &base_chars[0]));
	while (base[base_type] != '\0')
	{
		base_chars[base_type] = base[base_type];
		base_type++;
	}
	ft_base_transform(nbr, base_type, base_chars, values, &i);
	while (i >= 0)
	{
		write(1, &values[i], 1);
		i--;
	}
	base_chars[0] = '\n';
	write(1, &base_chars[0], 1);
	nbr++;
}

int main(void)
{
	char base[] = "abcde";
	int nbr = 46;
	ft_putnbr_base(nbr, base);
}

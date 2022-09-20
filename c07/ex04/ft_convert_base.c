/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 21:12:38 by saeby             #+#    #+#             */
/*   Updated: 2022/09/14 13:39:09 by saeby            ###   ########.fr       */
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
char	*ft_convert_base(char *nbr, char *base_from, char *base_to);

/*
int	main(int argc, char *argv[])
{
	char	*to_print;

	(void) argc;
	to_print = ft_convert_base(argv[1], argv[2], argv[3]);
	printf("%s\n", to_print);
}
*/

int	ft_convert_to_b10(char *nbr, char *base_from, int base_type, int *i)
{
	int	sum;
	int	j;
	int	k;

	(void) base_type;
	j = ft_strlen(nbr) - 1;
	k = 0;
	sum = 0;
	while (j > *i)
	{
		sum += base10_value(nbr[j], base_from) * ft_power(base_type, k);
		k++;
		j--;
	}
	return (sum);
}

void	ft_convert_to_base_n(int nbr, int base_type, char *response, int *i)
{
	int	value;

	value = nbr % base_type;
	response[*i] = value + 48;
	*i = *i + 1;
	if (nbr / base_type > 0)
	{
		nbr = nbr / base_type;
		ft_convert_to_base_n(nbr, base_type, response, i);
	}
}

void	ft_fill_response(char *response, char *base_to, char *temp, int *s)
{
	int	i;
	int	j;

	i = ft_strlen(temp) - 1;
	if (*s % 2 == 0)
	{
		j = 0;
		while (i >= 0)
		{
			response[j] = base_to[temp[i] - 48];
			j++;
			i--;
		}
	}
	else
	{
		j = 1;
		response[0] = '-';
		while (i >= 0)
		{
			response[j] = base_to[temp[i] - 48];
			j++;
			i--;
		}
	}
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		base_10;
	int		i;
	char	*temp;
	char	*response;
	int		s;

	if (ft_base_error(base_from) || ft_base_error(base_to))
		return (NULL);
	if (ft_nbr_error(nbr, &s, &i))
		return ("-2");
	temp = malloc(ft_strlen(nbr) * sizeof(char));
	base_10 = ft_convert_to_base_10(nbr, base_from, ft_strlen(base_from), &i);
	i = 0;
	ft_convert_to_base_n(base_10, ft_strlen(base_to), temp, &i);
	response = malloc((ft_strlen(temp) + 2) * sizeof(char));
	ft_fill_response(response, base_to, temp, &s);
	free(temp);
	temp = NULL;
	return (response);
}

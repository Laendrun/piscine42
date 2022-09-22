/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:26:13 by saeby             #+#    #+#             */
/*   Updated: 2022/09/22 20:32:00 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	check_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	count_args(char *str, char *charset)
{
	int	i;
	int	ac;

	i = 0;
	ac = 0;
	while (str[i] != '\0' && !check_sep(str[i], charset))
	{
		if (check_sep(str[i], charset) && !check_sep(str[i + 1], charset))
			ac++;
		i++;
	}
	ac++;
	return (ac);
}

void	fill_table(char **tmp, char *str, int *c, char *charset)
{
	while (c[2] < c[1])
	{
		if (!check_sep(str[c[2]], charset))
		tmp[c[0]][c[3]++] = str[c[2]++];
	}
	if (str[c[2] + 1] == 0)
		tmp[c[0]][c[3]++] = str[c[2]];
	tmp[c[0]++][c[3]] = 0;
	c[2]++;
}

/* 
 * c[0] -> i
 * c[1] -> j
 * c[2] -> k
 * c[3] -> l
 */

char	**ft_split(char *str, char *charset)
{
	char	**tmp;
	int		ac;
	int		c[4];

	ac = count_args(str, charset);
	tmp = malloc((ac + 1) * sizeof(char *));
	c[0] = 0;
	c[1] = 0;
	c[2] = 0;
	while (str[c[1]] && c[0] < ac)
	{
		tmp[c[0]] = malloc(50 * sizeof(char *));
		c[3] = 0;
		if ((check_sep(str[c[1]], charset) || str[c[1] + 1] == 0)
			&& (!check_sep(str[c[1] + 1], charset) || str[c[1] + 1] != 0))
			fill_table(tmp, str, c, charset);
		c[1]++;
	}
	tmp[ac] = 0;
	return (tmp);
}
/*
int	main(void)
{
	char string[] = "   \t";
	char sep[] = " \t";
	int i = 0;

	char **str = ft_split(string, sep);

	while (str[i])
	{
		printf("str[%d]: %s\n", i, str[i]);
		i++;
	}
}
*/

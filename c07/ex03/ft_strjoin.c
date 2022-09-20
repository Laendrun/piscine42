/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:53:24 by saeby             #+#    #+#             */
/*   Updated: 2022/09/14 13:43:06 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	fill_str(char *str, int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < size)
	{
		while (strs[i][j])
			str[k++] = strs[i][j++];
		j = 0;
		while (sep[j++] && i < size - 1)
			str[k++] = sep[j++];
		str[k] = '\0';
		j = 0;
		i++;
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		to_allocate;
	int		i;

	if (size == 0)
	{
		*result = malloc(0);
		return (result);
	}
	to_allocate = 0;
	to_allocate += ft_strlen(sep) * (size - 1);
	i = 0;
	while (i < size)
	{
		to_allocate += ft_strlen(strs[i]);
		i++;
	}
	to_allocate++;
	result = malloc(to_allocate);
	fill_str(result, size, strs, sep);
	return (result);
}
/*
int	main(int argc, char *argv[])
{
	char sep[] = ", ";
	printf("%s\n", ft_strjoin(argc, argv, sep));
	//printf("%lu\n", sizeof(int));
}
*/

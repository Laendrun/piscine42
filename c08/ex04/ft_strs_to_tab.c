/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 10:26:40 by saeby             #+#    #+#             */
/*   Updated: 2022/09/21 14:40:44 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "ft_stock_str.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = (char *) malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int			i;
	t_stock_str	*tab;

	if (ac <= 0)
		return (NULL);
	tab = malloc(((ac + 1) * sizeof(t_stock_str)));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		tab[i].size = ft_strlen(av[i]);
		tab[i].str = av[i];
		tab[i].copy = ft_strdup(av[i]);
		i++;
	}
	tab[i].str = 0;
	tab[i].size = 0;
	tab[i].copy = 0;
	return (tab);
}
/*
int	main(int argc, char *argv[])
{
	int	i = 0;
	//t_stock_str *strs_tab =  ft_strs_to_tab(argc, argv);
	(void) argv;	
	while (i < argc)
	{
		//printf("strs_tab[%d].size : %d\n", i, strs_tab[i].size);
		//printf("strs_tab[%d].str : %s\n", i, strs_tab[i].str);
		//printf("strs_tab[%d].copy : %s\n", i, strs_tab[i].copy);
		i++;
	}

	return (0);
}
*/

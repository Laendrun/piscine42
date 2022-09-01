/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:50:43 by saeby             #+#    #+#             */
/*   Updated: 2022/09/01 17:15:39 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

int	ft_str_is_alpha(char *str)
{
	int		i;	
	char	*x;

	*x = str;
	i = 0;
	while (x[i] != '\0')
	{
		if (!(x[i] >= 'a' && x[i] <= 'z') || (x[i] >= 'A' && x[i] <= 'Z'))
		{
			return (0);
		}
		else
		{
			i++;
		}
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:13:07 by saeby             #+#    #+#             */
/*   Updated: 2022/09/04 21:31:44 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	dest_len = ft_strlen(dest);
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && i < size)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (! (size == 0 || dest_len > size))
		dest[i] = '\0';
	return (i);
}

/*
int main(void)
{
	char dest[50] = "test";
	char src[] = "0123456789";

	printf("%d", ft_strlcat(dest, src, 50));
}
*/

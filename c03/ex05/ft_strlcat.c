/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 17:13:07 by saeby             #+#    #+#             */
/*   Updated: 2022/09/08 13:17:16 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

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
	unsigned int	src_len;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
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
	return (dest_len + src_len);
}

/*
int main(void)
{
	char dest[40] = "test";
	char src[] = "6789";
	char dest2[40] = "test";
	char src2[] = "6789";

	printf("%d\n", ft_strlcat(dest, src, 20));
	printf("%lu\n", strlcat(dest2, src2, 20));
}
*/

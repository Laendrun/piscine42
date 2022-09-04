/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 16:13:09 by saeby             #+#    #+#             */
/*   Updated: 2022/09/04 21:26:46 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>
#include <string.h>
*/

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

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

/*
int main(void)
{
	char haystack[] = "est123test";
	char needle[] = "123";
	
	printf("ft_strstr > %s\n", ft_strstr(haystack, needle));
	printf("strstr > %s\n", strstr(haystack, needle));
}
*/

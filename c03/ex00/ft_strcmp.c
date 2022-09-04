/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:54:52 by saeby             #+#    #+#             */
/*   Updated: 2022/09/03 21:03:49 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

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
/* return s1[i] - s2[i]
 * if the values are the same, returns 0, the strings are the same
 * if the values are different, returns a number less than or more than 0
 */

/*
 * int main(void)
 * {
 *		char s1[] = "test";
 *		char s2[] = "test2";
 *
 *		printf("%d", ft_strcmp(s1, s2));
 * }
 */

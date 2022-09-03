/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 17:34:49 by saeby             #+#    #+#             */
/*   Updated: 2022/09/01 17:43:00 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_str_is_lowercase(char *str)
{
	int	i;
	
	i	= 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
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

int main(void)
{
	char str1[] = "aegfhdhs";
	char str0[] = "aEgFhdhs";
	int res1 = ft_str_is_lowercase(str1);
	int res0 = ft_str_is_lowercase(str0);
	res1 = res1 + '0';
	res0 = res0 + '0';

	write(1, &res0, 1);
	write(1, &res1, 1);

}

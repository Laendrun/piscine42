/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 13:15:46 by saeby             #+#    #+#             */
/*   Updated: 2022/09/12 13:40:10 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_char_is_printable(char c)
{
	if (c < 32 || c > 126)
		return (0);
	return (1);
}

// get the index of a string like this ?
// "0123456789abcdef"[4] =?= 4
// tested, result, it works, so yeah great !

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!ft_char_is_printable(str[i]))
		{
			ft_putchar('\\');
			ft_putchar("0123456789aebcde"[str[i] / 16]);
			ft_putchar("0123456789aebcde"[str[i] % 16]);
		}
		i++;
	}
}

int	main(void)
{
	char str[] = "\n\t\v\f";
	ft_putstr_non_printable(str);
	//printf("%c\n", "0123456789aebcde"[11]);


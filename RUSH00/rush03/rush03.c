/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:25:17 by saeby             #+#    #+#             */
/*   Updated: 2022/09/03 04:08:58 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char value);

void	set_chars(char *characters)
{
	characters[0] = 'A';
	characters[1] = 'A';
	characters[2] = 'C';
	characters[3] = 'C';
	characters[4] = 'B';
	characters[5] = 'B';
	characters[6] = ' ';
}

void	ft_println(char left, char middle, char right, int x)
{
	int	current_x;

	current_x = 0;
	while (current_x < x)
	{
		if (current_x == 0)
		{
			ft_putchar(left);
		}
		else if (current_x == x - 1)
		{
			ft_putchar(right);
		}
		else
		{
			ft_putchar(middle);
		}
		current_x++;
	}
}	

void	rush(int x, int y)
{
	int		current_y;
	char	chars[8];

	current_y = 0;
	set_chars(chars);
	while (current_y < y)
	{
		if (current_y == 0)
		{
			ft_println(chars[0], chars[4], chars[2], x);
		}
		else if (current_y == y - 1)
		{
			ft_println(chars[1], chars[4], chars[3], x);
		}
		else
		{
			ft_println(chars[5], chars[6], chars[5], x);
		}
		ft_putchar('\n');
		current_y++;
	}
}

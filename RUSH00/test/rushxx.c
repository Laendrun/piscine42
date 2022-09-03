/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 23:25:17 by saeby             #+#    #+#             */
/*   Updated: 2022/09/03 04:10:38 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char value);

void	set_chars(char *characters)
{
	characters[0] = '+';
	characters[1] = '+';
	characters[2] = '+';
	characters[3] = '+';
	characters[4] = '-';
	characters[5] = '|';
	characters[6] = '\0';
}

void	ft_println(char left, char middle, char right, int x, int current_y, int y)
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
			if (current_y != 0 && current_y != y-1)
			{
				if (current_x % 2 == 0)
				{
					middle = '2';
				}
				else if (current_x % 2 == 1)
				{
					middle = '4';
				}
			}	

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
			ft_println(chars[0], chars[4], chars[2], x, current_y, y);
		}
		else if (current_y == y - 1)
		{
			ft_println(chars[1], chars[4], chars[3], x, current_y, y);
		}
		else
		{
			ft_println(chars[5], chars[6], chars[5], x, current_y, y);
		}
		ft_putchar('\n');
		current_y++;
	}
}

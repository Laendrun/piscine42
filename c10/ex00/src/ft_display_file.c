/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 20:34:12 by saeby             #+#    #+#             */
/*   Updated: 2022/09/22 20:53:55 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_puterror(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
}

int	print_f_content(char *f_name)
{
	int		f_desc;
	int		br;
	char	t;

	f_desc = open(f_name, O_RDONLY);
	if (f_desc == -1)
		return (-1);
	br = 1;
	while (br != 0)
	{
		br = read(f_desc, &t, 1);
		ft_putchar(t);
	}
	return (0);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		ft_puterror("File name missing.\n");
	else if (ac > 2)
		ft_puterror("Too many arguments.\n");
	else
	{
		if (print_f_content(av[1]) == -1)
		{
			ft_puterror("Cannot read file.\n");
			return (-1);
		}
	}
	return (0);
}

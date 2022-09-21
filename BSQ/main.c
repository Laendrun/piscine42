/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 22:58:30 by saeby             #+#    #+#             */
/*   Updated: 2022/09/21 12:08:21 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	main(int ac, char **av)
{
	int	i;

	if (ac == 2)
	{
		bsq(av[1]);
	}
	else if (ac == 1)
	{
		ft_putstr("not yet implemented");
	}
	else
	{
		i = 1;
		while (i < ac)
		{
			bsq(av[i]);
			ft_putchar('\n');
			i++;
		}
	}
	return (0);
}

int	bsq(char *map_file)
{
	t_mapi		map_info;
	char		*map_f_buf;
	char		**map_2d;
	t_square	square;
	int			size;

	square.size = 0;
	square.x = 0;
	square.y = 0;
	map_info = get_map_info(map_file);
	if (map_info.empt == 0 || map_info.f_size < 3)
		return (map_error());
	map_f_buf = malloc((map_info.f_size + map_info.lines) * sizeof(char));
	fill_map_buffer(map_f_buf, map_file);
	map_info.cols = get_col_count(map_f_buf);
	map_2d = ft_split(map_f_buf, &map_info);
	size = map_info.cols;
	if (map_info.cols >= map_info.lines)
		size = map_info.lines;
	if (map_2d[0][0] == 0)
		return (map_error());
	square = find_biggest_square(map_2d, size, &map_info);
	mark_biggest_square(map_2d, square, &map_info);
	print_map(map_2d, &map_info);
	return (0);
}

int	stdin_map(void)
{
	int		br;
	int		f_desc;

	br = 1;
	f_desc = open("mapx", O_RDONLY);
	printf("f_desc: %d\n", f_desc);
	// read the first line, has to start with a number (line count)
	// when we have the line count we can loop until we have reached the 
	// maximum number of lines
	// each time we pass a line, append it to the file mapx

	

}


int	clear_map(char *map_file)
{
	char	tmp;
	char	empty;
	int		br;
	int		i;
	int		f_desc;

	i = 0;
	br = 1;
	empty = 0;
	f_desc = open("mapx", O_CREAT, 0666);
	while (br != 0)
	{
		br = read(f_desc, &tmp, 1);
		write(f_desc, &empty, 1);
	}
	return (0);
}

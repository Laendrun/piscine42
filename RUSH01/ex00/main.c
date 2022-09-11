/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 12:35:23 by saeby             #+#    #+#             */
/*   Updated: 2022/09/11 20:45:28 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

#define DEBUG

#ifdef DEBUG
# define MODE 1
#else
# define MODE 0
#endif


/*
./a.out "2 3 1 3 2 1 4 2 2 1 3 2 2 3 1 2"
./a.out "2 2 1 2 2 1 4 3 3 4 1 2 2 1 2 2"
./a.out "1 2 4 2 2 5 2 1 3 2 1 2 2 4 3 3 2 3 1 2"
./a.out "4 1 2 3 2 2 1 3 2 2 4 3 2 3 2 3 4 1 3 1 2 3 2 3"
./a.out "1 2 3 3 4 3 2 2 1 2 3 2 4 3 1 7 4 3 4 2 2 4 1 2 2 3 4 4"
./a.out "4 3 4 1 5 4 3 2 2 4 2 4 1 3 5 4 3 3 5 2 3 1 3 2 2 1 2 3 2 4 3 3"
./a.out "4 2 2 3 3 3 1 6 2 1 3 2 2 4 3 4 2 2 3 2 5 3 3 4 4 2 1 2 4 4 4 3 1 2 3 2"
*/

int	main(int argc, char *argv[])
{
	argv[1] = "4 3 2 1 1 2 2 2 4 3 2 1 1 2 2 2";
	//argv[1] = "2 1 4 3 2 2 1 2 3 4 1 2 2 1 2 2";
	//argv[1] = "4 2 2 3 3 3 1 6 2 1 3 2 2 4 3 4 2 2 3 2 5 3 3 4 4 2 1 2 4 4 4 3 1 2 3 2";
	int	**table;
	int	*rules_input;
	int	som;

	if (!check_params(argc))
	{
		ft_print_error();
		return (1);
	}
	som = size_of_map(argv[1]);
	rules_input = get_rules(argv[1], som * 4);
	
	if (!check_rules_content(rules_input, som))
	{
		ft_print_error();
		return (1);
	}
	
	table = create_table(som);
	fill_table(table, rules_input, som);
	print_table(table, som, MODE);
}

int	*get_rules(char *rules, int size)
{
	int	*rules_input;
	int	i;
	int	j;

	rules_input = malloc(size * sizeof(int));
	i = 0;
	j = 0;
	while (rules[i] != 0)
	{
		if (rules[i] != ' ')
		{
			rules_input[j] = rules[i] - '0';
			j++;
		}
		i++;
	}
	return (rules_input);
}

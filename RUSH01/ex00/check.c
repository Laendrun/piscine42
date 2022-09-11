/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybensegh <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 19:24:56 by ybensegh          #+#    #+#             */
/*   Updated: 2022/09/11 15:57:22 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	check_params(int argc)
{
	if (argc != 2)
		return (0);
	return (1);
}

int	check_rules_format(char *rules)
{
	int	i;

	i = 0;
	if (!(ft_is_numeric(rules[i])))
		return (0);
	i++;
	while (rules[i])
	{
		if ((ft_is_numeric(rules[i]) || rules[i] == ' '))
		{
			if (!(ft_is_numeric(rules[i]) && ft_is_numeric(rules[i - 1])))
				i++;
			else
				return (0);
		}
		else
			return (0);
	}
	return (1);
}

int	calc_sum(int *rules_input, int size, int index)
{
	int	sum;
	int	i;

	sum = 0;
	i = index;
	while (i < (size + index))
	{
		sum += rules_input[i];
		i++;
	}
	return (sum);
}

int	calc_limit(int size)
{
	int	sum;
	int	i;

	i = size;
	sum = 0;
	while (i > 0)
	{
		sum += i;
		i--;
	}
	return (sum);
}

int	check_rules_strong_hor(int *rules_input, int size)
{
	int	i;
	int	limit;

	limit = calc_limit(size);
	i = 0;
	while (i < size)
	{
		if (rules_input[i] == size && rules_input[i + size] != 1)
			return (-1);
		if (rules_input[i + size] == size && rules_input[i] != 1)
			return (-2);
		if (calc_sum(rules_input, size, 0) > limit || calc_sum(rules_input, size, size) > limit)
			return (-3);
		i++;
	}

	return (1);
}

int	check_rules_strong_ver(int *rules_input, int size)
{
	int	i;
	int	limit;

	limit = calc_limit(size);
	i = size*2;
	while (i < size * 3)
	{
		if (rules_input[i] == size && rules_input[i + size] != 1)
			return (-1);
		if (rules_input[i + size] == size && rules_input[i] != 1)
			return (-2);
		if (calc_sum(rules_input, size, size * 3) > limit || calc_sum(rules_input, size * 3, size * 4))
		   return (-3);	
		i++;
	}
	return (1);
}

int	check_rules_strong(int *rules_input, int size)
{
	return check_rules_strong_hor(rules_input, size) && check_rules_strong_ver(rules_input, size);
}

int	check_rules_content(int *rules_input, int size)
{
	return check_rules_strong(rules_input, size);
}

int	ft_is_numeric(char c)
{
	if (!(c >= '0' && c <= '9'))
		return (0);
	return (1);
}

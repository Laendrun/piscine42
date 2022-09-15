/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_boolean.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 17:07:21 by saeby             #+#    #+#             */
/*   Updated: 2022/09/14 18:45:17 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BOOLEAN_H
# define FT_BOOLEAN_H
# define EVEN(nbr) ((nbr % 2) == 0 ? 1 : 0) 
# define EVEN_MSG "I have an even number of arguments.\n"
# define ODD_MSG "I have an odd number of arguments.\n"
# define SUCCESS 0
# include <unistd.h>

enum e_bool
{
	FALSE,
	TRUE
};

typedef enum e_bool	t_bool;

void	ft_putstr(char *str);
t_bool	ft_is_even(int nbr);

#endif

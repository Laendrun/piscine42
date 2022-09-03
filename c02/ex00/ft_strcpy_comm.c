/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 07:55:09 by saeby             #+#    #+#             */
/*   Updated: 2022/09/01 08:09:56 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	// iterate over src until EOF
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	// add EOF to the last index of dest
	dest[i] = '\0';
	//   ^ this will not remove last letter because we have already made an i++ before exiting while loop

	// as man strcpy says, the function returns the value of the destination
	return (dest);
}

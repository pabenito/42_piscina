/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 05:59:14 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/11 12:30:08 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}

// Read the file and does nothing. Only to advance the read pointer.
int	read_to_trush(int file, int bytes)
{
	char	*buffer;
	int		nbytes;

	buffer = (char *)malloc(bytes * sizeof(char));
	nbytes = read(file, buffer, bytes);
	free(buffer);
	if (nbytes != bytes)
		return (-1);
	return (0);
}

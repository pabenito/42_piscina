/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:12:04 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/12 12:35:42 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int	malloc_buffer(char **buffer, int rows, int cols)
{
	*buffer = (char *)malloc((rows * (cols + 1)) * sizeof(char));
	if (*buffer == NULL)
		return (-1);
	return (0);
}

int	malloc_matrix(char ***matrix, int rows, int cols)
{
	int	row;

	*matrix = (char **)malloc(rows * cols * sizeof(char *));
	if (*matrix == NULL)
		return (-1);
	row = 0;
	while (row < rows)
	{
		(*matrix)[row] = (char *)malloc(cols * sizeof(char));
		row++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_extra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:58:50 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/12 13:10:50 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read_extra.h"

int	is_valid_input_char(char c, t_map *map)
{
	return (c == map->empty || c == map->obstacle);
}

int	map_to_str_pos(int row, int col, t_map *map)
{
	return (row * (map->cols + 1) + col);
}

// Close the file and open again
int	reopen_file(char *file_path, int *file)
{
	close(*file);
	*file = open(file_path, O_RDONLY);
	if (*file == ERROR)
		return (ERROR);
	return (0);
}

// \n included
int	count_line_length(char buffer[], int index, ssize_t size)
{
	int	i;

	i = 0;
	while (index + i < size)
	{
		if (buffer[index + i] == '\n')
			return (i + 1);
		i++;
	}
	return (ERROR);
}

// Count the number of cols the matrix has
int	count_matrix_columns(int file, t_map *map, int info_line_length)
{
	char	*buffer;
	ssize_t	nbytes;
	char	c;

	buffer = (char *)malloc(info_line_length * sizeof(char));
	nbytes = read(file, buffer, info_line_length);
	free(buffer);
	if (nbytes != info_line_length)
		return (ERROR);
	map->cols = 0;
	nbytes = read(file, &c, 1);
	while (nbytes == 1 && c != '\n')
	{
		map->cols++;
		nbytes = read(file, &c, 1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 05:40:47 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/12 14:10:15 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

// Creates the map matrix from the buffer string
int	fill_matrix_from_str(t_map *map, char *buffer)
{
	int	row;
	int	col;
	int	str_index;

	row = 0;
	while (row < map->rows)
	{
		col = 0;
		while (col < map->cols)
		{
			str_index = map_to_str_pos(row, col, map);
			if (!is_valid_input_char(buffer[str_index], map))
				return (ERROR);
			map->matrix[row][col] = buffer[str_index];
			col++;
		}
		str_index = map_to_str_pos(row, col, map);
		if (row < map->rows && col == map->cols
			&& buffer[str_index] != '\n')
			return (ERROR);
		row++;
	}
	return (0);
}

// Reads the map info characters: empty, obstacle, full
int	read_map_info_characters(t_map *map, char buffer[], int index)
{
	if (!is_printable(buffer[index]))
		return (ERROR);
	map->empty = buffer[index];
	if (!is_printable(buffer[index + 1]))
		return (ERROR);
	map->obstacle = buffer[index + 1];
	if (!is_printable(buffer[index + 2]))
		return (ERROR);
	map->full = buffer[index + 2];
	if (map->empty == map->obstacle
		|| map->empty == map->full
		|| map->obstacle == map->full)
		return (ERROR);
	return (0);
}

// Reads the map info: the first line in the file
int	read_map_info(int file, t_map *map, int *info_line_length)
{
	char	buffer[MAX_ROWS_DIGITS + 3];
	ssize_t	nbytes;
	int		i;

	nbytes = read(file, buffer, MAX_ROWS_DIGITS + 3);
	if (nbytes <= 4)
		return (ERROR);
	*info_line_length = count_line_length(buffer, 0, MAX_ROWS_DIGITS + 3);
	map->rows = 0;
	i = 0;
	while (i < *info_line_length - 3 && is_digit(buffer[i]))
	{
		map->rows = map->rows * 10;
		map->rows = map->rows + buffer[i] - '0';
		i++;
	}
	if (i < *info_line_length - 4)
		return (ERROR);
	if (read_map_info_characters(map, buffer, i) == ERROR)
		return (ERROR);
	return (0);
}

// Reads the map from the file and creates the matrix
int	read_map_matrix(int file, t_map *map, int info_line_length)
{
	char	*buffer;
	ssize_t	nbytes;

	if (malloc_buffer(&buffer, map->rows, map->cols) == ERROR)
		return (ERROR);
	if (read_to_trush(file, info_line_length) == ERROR)
		return (ERROR);
	nbytes = read(file, buffer, map->rows * (map->cols + 1));
	if (nbytes != map->rows * (map->cols + 1))
		return (ERROR);
	if (malloc_matrix(&map->matrix, map->rows, map->cols) == ERROR)
		return (ERROR);
	if (fill_matrix_from_str(map, buffer) == ERROR)
		return (ERROR);
	free(buffer);
	return (0);
}

// Reads the map from the file and creates the map struct
int	read_map(char *file_path, t_map *map)
{
	int	file;
	int	info_line_length;

	map->matrix = NULL;
	file = open(file_path, O_RDONLY);
	if (file == -1)
		return (ERROR);
	if (file == ERROR)
		return (ERROR);
	if (read_map_info(file, map, &info_line_length) == ERROR)
		return (ERROR);
	if (reopen_file(file_path, &file) == ERROR)
		return (ERROR);
	if (count_matrix_columns(file, map, info_line_length) == ERROR)
		return (ERROR);
	if (reopen_file(file_path, &file) == ERROR)
		return (ERROR);
	if (read_map_matrix(file, map, info_line_length) == ERROR)
		return (ERROR);
	close(file);
	return (0);
}

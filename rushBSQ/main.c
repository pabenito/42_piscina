/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:26:31 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/12 14:11:47 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
#include "max_square.h"
#include "print_solution.h"
#include "read.h"
#include "free.h"

void	solve_the_map(char *file_path)
{
	t_square	max_square;
	t_map		map;

	if (read_map(file_path, &map) == ERROR)
	{
		write(1, "map error\n", 10);
		if (map.matrix != NULL)
			matrix_free(map);
	}
	else
	{
		find_max_square_in_the_map(map, &max_square);
		print_map_with_max_square(map, max_square);
		matrix_free(map);
	}
}

int	read_filepath_from_user(char *buffer)
{
	int	nbytes;

	nbytes = read(STDIN_FILENO, buffer, sizeof(buffer) - 1);
	if (nbytes <= 0)
		return (ERROR);
	buffer[nbytes] = '\0';
	return (0);
}

int	main(int argc, char *argv[])
{
	char	file_path[100];
	int		i;

	if (argc < 2)
	{
		read_filepath_from_user(file_path);
		solve_the_map(file_path);
	}
	else
	{
		i = 1;
		while (i < argc)
		{
			solve_the_map(argv[i]);
			if (i < argc - 1)
				write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}

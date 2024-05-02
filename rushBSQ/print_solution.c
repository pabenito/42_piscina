/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:47:57 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/11 21:00:57 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_solution.h"

void	fill_map_with_solution(t_map map, t_square max_square)
{
	int	row;
	int	col;

	row = max_square.row;
	while (row < max_square.row + max_square.side)
	{
		col = max_square.col;
		while (col < max_square.col + max_square.side)
		{
			map.matrix[row][col] = map.full;
			col++;
		}
		row++;
	}
}

void	print_map(t_map map)
{
	int	row;
	int	col;

	row = 0;
	while (row < map.rows)
	{
		col = 0;
		while (col < map.cols)
		{
			write(1, &map.matrix[row][col], 1);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

void	print_map_with_max_square(t_map map, t_square max_square)
{
	fill_map_with_solution(map, max_square);
	print_map(map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_square.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:41:50 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/12 11:52:06 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "max_square.h"

void	find_max_square_in_the_map(t_map map, t_square *max_square)
{
	t_square	current_square;

	max_square->row = 0;
	max_square->col = 0;
	max_square->side = 0;
	current_square.row = 0;
	while (current_square.row < map.rows - max_square->side)
	{
		current_square.col = 0;
		while (current_square.col < map.cols - max_square->side)
		{
			max_square_posible(map, &current_square);
			if (current_square.side > max_square->side)
			{
				max_square->row = current_square.row;
				max_square->col = current_square.col;
				max_square->side = current_square.side;
			}
			current_square.col++;
		}
		current_square.row++;
	}
}

void	max_square_posible(t_map map, t_square *square)
{
	square->side = 0;
	while (is_a_posible_square(map, square))
		square->side++;
	square->side--;
}

int	is_a_posible_square(t_map map, t_square *square)
{
	int	i;

	if (square->row + square->side > map.rows
		|| square->col + square->side > map.cols)
		return (0);
	i = 0;
	while (square->row + i < map.rows && i < square->side)
	{
		if (map.matrix[square->row + i]
			[square->col + square->side - 1] == map.obstacle)
			return (0);
		i++;
	}
	i = 0;
	while (square->col + i < map.cols && i < square->side - 1)
	{
		if (map.matrix[square->row + square->side - 1]
			[square->col + i] == map.obstacle)
			return (0);
		i++;
	}
	return (1);
}

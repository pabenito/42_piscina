/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepena-m <cepena-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 15:43:52 by cepena-m          #+#    #+#             */
/*   Updated: 2023/10/01 19:22:03 by cepena-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	**ft_create_matrix(int rows, int cols)
{
	int	**matrix;
	int	row;

	matrix = (int **)malloc(rows * sizeof(int *));
	row = 0;
	while (row < rows)
	{
		matrix[row] = (int *)malloc(cols * sizeof(int));
		row++;
	}
	return (matrix);
}

void	ft_free_matrix(int **matrix, int rows)
{
	int	row;

	row = 0;
	while (row < rows)
	{
		free(matrix[row]);
		row++;
	}
	free(matrix);
}

void	ft_init_matrix(int **matrix, int rows, int cols)
{
	int	row;
	int	col;

	row = 0;
	while (row < rows)
	{
		col = 0;
		while (col < cols)
		{
			matrix[row][col] = 0;
			col++;
		}
		row++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 12:14:13 by cepena-m          #+#    #+#             */
/*   Updated: 2023/10/01 22:41:51 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_correct_views(int **matrix, int **expected_views);
int		**ft_create_matrix(int rows, int cols);
void	ft_init_matrix(int **matrix, int rows, int cols);
void	ft_free_matrix(int **matrix, int rows);
void	ft_print_solution(int **matrix);

int	ft_is_distinct(int **matrix, int row, int col)
{
	int	i;
	int	j;

	j = 0;
	while (j < col)
	{
		if (matrix[row][j] == matrix[row][col])
			return (0);
		j++;
	}
	i = 0;
	while (i < row)
	{
		if (matrix[i][col] == matrix[row][col])
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_solution(int **views, int **matrix, int row, int col)
{
	return (row == 3 && col == 3
		&& ft_is_distinct(matrix, row, col)
		&& ft_correct_views(matrix, views));
}

void	ft_update_position(int *next_row, int *next_col, int row, int col)
{
	if (col == 3)
	{
		*next_row = row + 1;
		*next_col = 0;
	}
	else
	{
		*next_row = row;
		*next_col = col + 1;
	}	
}

int	ft_backtrack(int **views, int **matrix, int row, int col)
{
	int	n;
	int	next_row;
	int	next_col;

	n = 1;
	while (n <= 4)
	{
		matrix[row][col] = n;
		if (row == 3 && col == 3)
		{
			if (ft_is_solution(views, matrix, row, col))
				return (1);
		}
		else if (ft_is_distinct(matrix, row, col))
		{
			ft_update_position(&next_row, &next_col, row, col);
			if (ft_backtrack(views, matrix, next_row, next_col))
				return (1);
		}
		n++;
	}
	return (0);
}

int	**ft_rush(int **views)
{
	int	**matrix;

	matrix = ft_create_matrix(4, 4);
	ft_init_matrix(matrix, 4, 4);
	if (ft_backtrack(views, matrix, 0, 0))
		return (matrix);
	else
	{
		ft_free_matrix(matrix, 4);
		return (NULL);
	}
}

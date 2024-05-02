/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 14:04:47 by cepena-m          #+#    #+#             */
/*   Updated: 2023/10/01 23:50:17 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		**ft_create_matrix(int rows, int cols);
void	ft_free_matrix(int **matrix, int rows);
void	ft_init_matrix(int **matrix, int rows, int cols);
void	ft_print_solution(int **matrix);

void	ft_compute_top_down(int **views, int **matrix)
{
	int	count;
	int	max;
	int	col;
	int	row;

	col = 0;
	while (col <= 3)
	{
		count = 0;
		max = 0;
		row = 0;
		while (row <= 3)
		{
			if (matrix[row][col] > max)
			{
				count++;
				max = matrix[row][col];
			}
			row++;
		}
		views[0][col] = count;
		col++;
	}
}

void	ft_compute_bottom_up(int **views, int **matrix)
{
	int	count;
	int	max;
	int	col;
	int	row;

	col = 0;
	while (col <= 3)
	{
		count = 0;
		max = 0;
		row = 3;
		while (row >= 0)
		{
			if (matrix[row][col] > max)
			{
				count++;
				max = matrix[row][col];
			}
			row--;
		}
		views[1][col] = count;
		col++;
	}
}

void	ft_compute_left_right(int **views, int **matrix)
{
	int	count;
	int	max;
	int	col;
	int	row;

	row = 0;
	while (row < 4)
	{
		count = 0;
		max = 0;
		col = 0;
		while (col < 4)
		{
			if (matrix[row][col] > max)
			{
				count++;
				max = matrix[row][col];
			}
			col++;
		}
		views[2][row] = count;
		row++;
	}
}

void	ft_compute_right_left(int **views, int **matrix)
{
	int	count;
	int	max;
	int	col;
	int	row;

	row = 0;
	while (row < 4)
	{
		count = 0;
		max = 0;
		col = 3;
		while (col >= 0)
		{
			if (matrix[row][col] > max)
			{
				count++;
				max = matrix[row][col];
			}
			col--;
		}
		views[3][row] = count;
		row++;
	}
}

int	ft_correct_views(int **matrix, int **expected_views)
{
	int	**views;
	int	row;
	int	col;

	views = ft_create_matrix(4, 4);
	ft_init_matrix(views, 4, 4);
	ft_compute_top_down(views, matrix);
	ft_compute_bottom_up(views, matrix);
	ft_compute_left_right(views, matrix);
	ft_compute_right_left(views, matrix);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (views[row][col] != expected_views[row][col])
			{
				ft_free_matrix(views, 4);
				return (0);
			}
			col++;
		}
		row++;
	}
	ft_free_matrix(views, 4);
	return (1);
}

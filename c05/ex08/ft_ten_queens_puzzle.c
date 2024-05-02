/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 14:04:51 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/12 17:19:17 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int	is_valid_board(int board[11][11], int row, int col)
{
	int	i;

	i = 0;
	while (i < row)
	{
		if (board[i][col])
			return (0);
		i++;
	}
	i = 1;
	while (row - i >= 0 && col - i >= 0)
	{
		if (board[row - i][col - i])
			return (0);
		i++;
	}
	i = 1;
	while (row - i >= 0 && col + i < 10)
	{
		if (board[row - i][col + i])
			return (0);
		i++;
	}
	return (1);
}

void	print_solution(int board[11][11])
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (row < 10)
	{
		col = 0;
		while (col < 10 && !board[row][col])
			col++;
		if (board[row][col])
		{
			c = col + '0';
			write(1, &c, 1);
		}
		row++;
	}
	write(1, "\n", 1);
}

int	ten_queens_rec(int board[11][11], int row)
{
	int	solution_count;
	int	col;

	solution_count = 0;
	col = 0;
	while (col < 10)
	{
		board[row][col] = 1;
		if (is_valid_board(board, row, col))
		{
			if (row == 9)
			{
				print_solution(board);
				solution_count++;
			}
			solution_count += ten_queens_rec(board, row + 1);
		}
		board[row][col] = 0;
		col++;
	}
	return (solution_count);
}

int	ft_ten_queens_puzzle(void)
{
	int	board[11][11];
	int	row;
	int	col;

	row = 0;
	while (row < 10)
	{
		col = 0;
		while (col < 10)
		{
			board[row][col] = 0;
			col++;
		}
		row++;
	}
	return (ten_queens_rec(board, 0));
}

int	main(void)
{
	printf("%d\n", ft_ten_queens_puzzle());
	return (0);
}

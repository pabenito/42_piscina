/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:29:55 by cepena-m          #+#    #+#             */
/*   Updated: 2023/10/01 23:47:17 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		**ft_create_matrix(int rows, int cols);
void	ft_free_matrix(int **matrix, int rows);

int	is_digit(char character)
{
	return (character >= '1' && character <= '4');
}

int	ft_pos_str(int row, int col)
{
	return (row * 8 + col * 2);
}

int	check_digit(char *input, int **views, int row, int col)
{
	if (!is_digit(input[ft_pos_str(row, col)]))
	{
		ft_free_matrix(views, 4);
		return (0);
	}
	return (1);
}

int	check_space(char *input, int **views, int row, int col)
{
	if (input[ft_pos_str(row, col) + 1] != ' ')
	{
		ft_free_matrix(views, 4);
		return (0);
	}
	return (1);
}

int	**ft_get_views(char *input)
{
	int	row;
	int	col;
	int	**views;

	views = ft_create_matrix(4, 4);
	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			if (!check_digit(input, views, row, col))
				return (NULL);
			views[row][col] = input[ft_pos_str(row, col)] - '0';
			if (row == 3 && col == 3 && input[ft_pos_str(row, col) + 1] == '\0')
				return (views);
			if (!check_space(input, views, row, col))
				return (NULL);
			col++;
		}
		row++;
	}
	return (views);
}

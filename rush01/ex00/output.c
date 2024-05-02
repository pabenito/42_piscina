/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cepena-m <cepena-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:58:17 by cepena-m          #+#    #+#             */
/*   Updated: 2023/10/01 19:58:42 by cepena-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_solution(int **matrix)
{
	int	row;
	int	col;
	int	character;

	row = 0;
	while (row < 4)
	{
		col = 0;
		while (col < 4)
		{
			character = matrix[row][col] + '0';
			write(1, &character, 1);
			if (col < 3)
				write(1, " ", 1);
			else
				write(1, "\n", 1);
			col++;
		}
		row++;
	}
}

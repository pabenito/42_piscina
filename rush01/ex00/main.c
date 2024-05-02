/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/01 11:10:13 by cepena-m          #+#    #+#             */
/*   Updated: 2023/10/01 23:30:21 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		**ft_get_views(char *input);
int		**ft_rush(int **views);
char	*ft_print_solution(int **matrix);
void	ft_free_matrix(int **matrix, int rows);

void	ft_print_and_free(int **views, int **matrix)
{
	ft_print_solution(matrix);
	ft_free_matrix(views, 4);
	ft_free_matrix(matrix, 4);
}

void	ft_print_error(int error)
{
	if (error)
		write(1, "Error\n", 6);
}

int	main(int argc, char *argv[])
{
	int	**views;
	int	**matrix;
	int	error;

	error = 0;
	if (argc != 2)
		error = 1;
	if (!error)
	{
		views = ft_get_views(argv[1]);
		if (views == NULL)
			error = 1;
	}
	if (!error)
	{
		matrix = ft_rush(views);
		if (matrix == NULL)
			error = 1;
	}
	if (!error)
		ft_print_and_free(views, matrix);
	ft_print_error(error);
	if (error)
		return (-1);
	return (0);
}

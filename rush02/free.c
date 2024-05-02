/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 23:26:40 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/08 23:33:34 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_line	*t_line;
struct	s_line
{
	char	*number;
	char	*str;
};

struct	s_number
{
	int		digits;
	int		number;
	char	*number_str;
	char	*str;
};

void	free_array_lines(t_line *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] != NULL)
		{
			if (array[i]->number != NULL)
				free(array[i]->number);
			if (array[i]->number != NULL)
				free(array[i]->str);
		}
		i++;
	}
	free(array);
}

void	free_array_numbers(struct s_number *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i].number_str);
		free(array[i].str);
		i++;
	}
	free(array);
}

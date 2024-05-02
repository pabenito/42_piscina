/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 11:28:20 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/06 12:25:58 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	*range = NULL;
	if (min >= max)
		return (0);
	*range = (int *)malloc((max - min) * sizeof(int));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i++;
	}
	return (max - min);
}

void	print_array(int *array, int size)
{
	int	i;

	printf("[");
	i = 0;
	while (i < size)
	{
		if (i == 0)
			printf("%d", array[i]);
		else
			printf(", %d", array[i]);
		i++;
	}
	printf("]\n");
}

/* int	main(void)
{
	int	*range;

	printf("%d\n", ft_ultimate_range(&range, -10, 10));
	print_array(range, 20);
	printf("%d\n", ft_ultimate_range(&range, 0, 1));
	print_array(range, 1);
	printf("%d\n", ft_ultimate_range(&range, 0, 0));
	printf("%p", range);
	return (0);
} */

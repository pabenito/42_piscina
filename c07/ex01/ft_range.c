/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 10:28:02 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/06 11:28:31 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	i;

	if (min >= max)
		return (NULL);
	array = (int *)malloc((max - min) * sizeof(int));
	if (array == NULL)
		return (NULL);
	i = 0;
	while (min + i < max)
	{
		array[i] = min + i;
		i++;
	}
	return (array);
}

/* void	print_array(int *array, int size)
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

int	main(void)
{
	print_array(ft_range(-10, 10), 20);
	print_array(ft_range(0, 1), 1);
	printf("%p", ft_range(0, 0));
	return (0);
} */

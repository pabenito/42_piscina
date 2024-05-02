/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 07:42:39 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/05 18:27:45 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	i;
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = nb;
	i = 2;
	while (i <= power)
	{
		result *= nb;
		i++;
	}
	return (result);
}

/* int	main(void)
{
	int	min;
	int	max;
	int	i;
	int	j;

	min = -1;
	max = 10;
	i = min;
	while (i <= max)
	{
		j = -1;
		while (j <= 3)
		{
			printf("Potencia(%d^%d): %d\n", i, j, ft_iterative_power(i, j));
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
} */
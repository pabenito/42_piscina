/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:09:11 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/05 18:28:29 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	return (nb * ft_recursive_power(nb, power - 1));
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
			printf("Potencia(%d^%d): %d\n", i, j, ft_recursive_power(i, j));
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
} */
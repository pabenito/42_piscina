/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 16:44:59 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/05 18:27:53 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	i;
	int	result;

	if (nb < 0)
		return (0);
	i = 1;
	result = 1;
	while (i <= nb)
		result *= i++;
	return (result);
}

/* int	main(void)
{
	int	min;
	int	max;
	int	i;

	min = -1;
	max = 10;
	i = min;
	while (i <= max)
	{
		printf("Factorial(%d): %d\n", i, ft_iterative_factorial(i));
		i++;
	}
	return (0);
} */
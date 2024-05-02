/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 07:37:41 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/05 18:27:50 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb <= 1)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
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
		printf("Factorial(%d): %d\n", i, ft_recursive_factorial(i));
		i++;
	}
	return (0);
} */
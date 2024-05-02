/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:20:58 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/05 18:27:37 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	if (index == 0)
		return (0);
	if (index == 1)
		return (1);
	return (ft_fibonacci(index - 2) + ft_fibonacci(index - 1));
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
		printf("Fibonacci(%d): %d\n", i, ft_fibonacci(i));
		i++;
	}
	return (0);
} */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 08:38:01 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/12 16:20:46 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

/* int	ft_sqrt(int nb)
{
	int	min;
	int	max;
	int	mean;
	int	square;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (nb);
	min = 1;
	max = nb / 2;
	while (min <= max)
	{
		mean = (min + max) / 2;
		square = mean * mean;
		if (square == nb)
			return (mean);
		if (square < nb)
			min = mean + 1;
		else
			max = mean - 1;
	}
	return (0);
} */

int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 0;
	while (i * i < nb && i < 46340)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}

/* int	main(void)
{
	int	min;
	int	max;
	int	i;

	printf("Square-root(%d): %d\n", -1, ft_sqrt(-1));
	printf("Square-root(%d): %d\n", 0, ft_sqrt(0));
	min = 1;
	max = 10;
	i = min;
	while (i <= max)
	{
		printf("Square-root(%d): %d\n", i, ft_sqrt(i));
		printf("Square-root(%d): %d\n", i * i, ft_sqrt(i * i));
		i++;
	}
	printf("Square-root(%d): %d\n", -1, ft_sqrt(-1));
	printf("Square-root(%d): %d\n", 0, ft_sqrt(0));
	return (0);
} */

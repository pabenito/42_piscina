/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:26:14 by pbenito-          #+#    #+#             */
/*   Updated: 2023/09/21 17:18:31 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

void	print_number(int *number, int digits)
{
	int		i;
	char	str[2];

	i = 0;
	while (i < digits)
	{
		sprintf(str, "%d", number[i]);
		write(1, &str[0], 1);
		i++;
	}
}

void	increase(int *number, int position, int digits)
{
	int	i;

	number[position]++;
	i = position + 1;
	while (i < digits)
	{
		number[i] = number[i - 1] + 1;
		i++;
	}
}

void	next(int *number, int digits)
{
	int	can_increase;
	int	i;

	i = digits - 1;
	can_increase = number[i] < 10 - digits + i;
	while (i >= 0 && !(number[i] < 10 - digits + i))
	{
		i--;
		can_increase = number[i] < 10 - digits + i;
	}
	if (i >= 0)
		increase(number, i, digits);
}

int	has_next(int *number, int digits)
{
	int	can_has_next;
	int	can_increase;
	int	i;

	can_has_next = 0;
	i = 0;
	while (!can_has_next && i < digits)
	{
		can_increase = number[i] < 10 - digits + i;
		if (can_increase)
			can_has_next = 1;
		i++;
	}
	return (can_has_next);
}

void	ft_print_combn(int n)
{
	int	number[10];
	int	i;

	i = 0;
	while (i < n)
	{
		number[i] = i;
		i++;
	}
	print_number(number, n);
	while (has_next(number, n))
	{
		write(1, ", ", 2);
		next(number, n);
		print_number(number, n);
	}
}

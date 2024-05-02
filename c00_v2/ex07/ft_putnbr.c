/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:26:14 by pbenito-          #+#    #+#             */
/*   Updated: 2023/09/21 20:49:33 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	digits(int n)
{
	int	digits;

	if (n == 0)
	{
		return (1);
	}
	else
	{
		digits = 0;
		while (n != 0)
		{
			n /= 10;
			digits++;
		}
		return (digits);
	}
}

void	get_digit_array(int n, int *array)
{
	int	n_digits;
	int	i;

	n_digits = digits(n);
	i = 0;
	while (i < n_digits)
	{
		array[n_digits - 1 - i] = n % 10;
		n /= 10;
		i++;
	}
}

void	ft_putnbr(int nb)
{
	char	c;
	char	str[12];
	int		array[12];
	int		n_digits;
	int		i;

	n_digits = digits(nb);
	i = 0;
	if (nb < 0)
	{
		c = '-';
		write(1, &c, 1);
		nb = -nb;
	}
	get_digit_array(nb, array);
	while (i < n_digits)
	{
		str[i] = array[i] + '0';
		i++;
	}
	write(1, str, n_digits);
}

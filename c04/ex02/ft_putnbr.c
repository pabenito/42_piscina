/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:33:38 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/05 09:31:56 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	digits(int n)
{
	int	digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n != 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

int	abs(int n)
{
	if (n > 0)
		return (n);
	else
		return (-n);
}

void	ft_putnbr(int nb)
{
	char	str[12];
	int		len;
	int		i;

	if (nb < 0)
		write(1, "-", 1);
	len = digits(nb);
	i = 0;
	while (i < len)
	{
		str[len - 1 - i] = abs(nb % 10) + '0';
		nb = abs(nb / 10);
		i++;
	}
	i = 0;
	while (i < len)
	{
		write(1, &str[i], 1);
		i++;
	}
}

/* int	main(void)
{
	int	min;
	int	max;
	int	i;

	min = -10;
	max = 10;
	i = min;
	while (i <= max)
	{
		ft_putnbr(i);
		i++;
	}
	ft_putnbr(-2147483648);
	return (0);
} */

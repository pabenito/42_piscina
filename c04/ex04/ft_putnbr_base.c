/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 09:20:17 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/05 09:30:32 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	digits_base(int n, char *base)
{
	int	digits;
	int	base_len;

	base_len = str_len(base);
	if (n == 0)
		return (1);
	digits = 0;
	while (n != 0)
	{
		n /= base_len;
		digits++;
	}
	return (digits);
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;
	int	len;

	len = str_len(base);
	if (len < 2)
		return (0);
	i = 0;
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	abs(int n)
{	
	if (n > 0)
		return (n);
	else
		return (-n);
}

void	ft_putnbr_base(int nb, char *base)
{
	char	str[50];
	int		base_len;
	int		len;
	int		i;

	if (is_valid_base(base))
	{
		base_len = str_len(base);
		if (nb < 0)
			write(1, "-", 1);
		len = digits_base(nb, base);
		i = 0;
		while (i < len)
		{
			str[len - 1 - i] = base[abs(nb % base_len)];
			nb = abs(nb / base_len);
			i++;
		}
		i = 0;
		while (i < len)
			write(1, &str[i++], 1);
	}
}

/* int	main(void)
{
	ft_putnbr_base(10, "0123456789");
	ft_putnbr_base(10, "01");
	ft_putnbr_base(10, "0123456789ABCDEF");
	ft_putnbr_base(-2147483648, "0123456789ABCDEF");
} */

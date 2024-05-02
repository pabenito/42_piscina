/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:26:14 by pbenito-          #+#    #+#             */
/*   Updated: 2023/09/21 20:49:28 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_comb(char i[], char j[])
{
	char	str[8];
	int		k;

	k = 0;
	while (i[k] != '\0')
	{
		str[k] = i[k];
		k++;
	}
	str[k] = ' ';
	k++;
	while (j[k - 3] != '\0')
	{
		str[k] = j[k - 3];
		k++;
	}
	if (i[0] != '9' || i[1] != '8' || j[0] != '9' || j[1] != '9')
	{
		k++;
		str[k] = ',';
		k++;
		str[k] = ' ';
	}
	write(1, str, k);
}

void	int_to_string(int n, char *str)
{
	int	x;

	if (n < 10)
	{
		str[0] = '0';
		str[1] = '0' + n;
	}
	else
	{
		x = (n - n % 10) / 10;
		str[0] = '0' + x;
		x = n % 10;
		str[1] = '0' + x;
	}
	str[2] = '\0';
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	char	i_str[3];
	char	j_str[3];

	i = 0;
	j = 0;
	while (i < 100)
	{
		j = i + 1;
		while (j < 100)
		{
			int_to_string(i, i_str);
			int_to_string(j, j_str);
			print_comb(i_str, j_str);
			j++;
		}
		i++;
	}
}

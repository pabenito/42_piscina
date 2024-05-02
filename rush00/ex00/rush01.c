/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 17:07:04 by fsoria            #+#    #+#             */
/*   Updated: 2023/09/26 20:32:33 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	check_size(int x, int y)
{
	char	*error;
	int		i;

	error = "Error: El rectangulo debe tener al menos una fila y una columna.\n";
	i = 0;
	if (x <= 0 || y <= 0)
	{
		while (error[i] != '\0')
		{
			ft_putchar(error[i]);
			i++;
		}
	}	
}

void	rush(int x, int y)
{
	int		c;
	int		f;

	check_size(x, y);
	f = 1;
	while (f <= y)
	{
		c = 1;
		while (c <= x)
		{
			if ((f == 1 && c == 1) || (c == x && f == y && f > 1 && c > 1))
				ft_putchar('/');
			else if ((c == 1 && f == y) || (f == 1 && c == x))
				ft_putchar('\\');
			else if (f == 1 || f == y || c == 1 || c == x)
				ft_putchar('*');
			else
				ft_putchar(' ');
			c++;
		}
		ft_putchar('\n');
		f++;
	}
}

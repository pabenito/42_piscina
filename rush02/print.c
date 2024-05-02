/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 23:29:33 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/08 23:29:35 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	print_trio(char *trio, struct s_number *dict, int size, int power)
{
	int	p_units;

	p_units = 1;
	if (trio[0] > '0')
	{
		if (print_hundreds(trio[0], dict, size))
			return (-1);
	}
	if (trio[1] > '0')
	{
		if (print_tens(&trio[1], dict, size, &p_units))
			return (-1);
	}
	if (p_units)
	{
		if (print_units(trio[2], dict, size))
			return (-1);		
	}
	if (print_power(power, dict, size))
		return (-1);
	return (0);
}

int	print_number(char **trios, struct s_number *dict, int size, int num_trios)
{
	int	i;

	i = num_trios - 1;
	while (i >= 0)
	{
		if (print_trio(trios[i], dict, size, i))
			return (-1);
		i--;
	}
	return (0);
}
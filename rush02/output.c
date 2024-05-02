/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 23:28:46 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/08 23:41:32 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*str_copy(char *dest, char *src);
int	str_cmp(char *s1, char *s2);
void	put_str(char *str);
int	str_length(char *str);
int	str_number_to_int(char *number);

typedef struct s_line	*t_line;
struct	s_line
{
	char	*number;
	char	*str;
};

struct	s_number
{
	int		digits;
	int		number;
	char	*number_str;
	char	*str;
};

int	print_number_from_dict(char *number, struct s_number *dict, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (str_cmp(dict[i].number_str, number) == 0)
		{
			put_str(dict[i].str);
			return (0);
		}
		i++;
	}
	return (1);
}

int	print_units(char c, struct s_number *dict, int size)
{
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	return (print_number_from_dict(str, dict, size));
}

int	print_tens(char *tens, struct s_number *dict, int size, int *print_units)
{
	char	str[3];

	if (tens[0] < '2' || (tens[0] == 2 && tens[1] == '0'))
	{
		if (print_number_from_dict(tens, dict, size))
			return (1);
		*print_units = 0; 
	}
	else
	{	
		if (tens[1] == '0')
			*print_units = 0;
		else
			*print_units = 1;
		str[0] = tens[0];
		str[1] = '0';
		str[2] = '\0';
		if (print_number_from_dict(str, dict, size))
			return (1);
	}
	return (0);
}

int	print_hundreds(char c, struct s_number *dict, int size)
{
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	if (print_number_from_dict(str, dict, size))
		return (1);
	if (print_number_from_dict("100", dict, size))
		return (1);
	return (0);
}

int	print_power(int power, struct s_number *dict, int size)
{
	char	*str;
	int		i;

	str = (char *)malloc((3 * power + 2) * sizeof(char));
	if (power == 0)
		return (0);
	str[0] = '1';
	i = 1;
	while (i <= 3 * power)
	{
		str[i] = '0';
		i++;
	}
	str[3 * power + 1] = '\0';
	if (print_number_from_dict(str, dict, size))
		return (1);
	return (0);
}
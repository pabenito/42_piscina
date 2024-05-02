/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 07:26:09 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/05 07:26:41 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_space(char c)
{
	return (c == '\t'
		|| c == '\n'
		|| c == '\v'
		|| c == '\f'
		|| c == '\r'
		|| c == ' ');
}

int	ft_atoi(char *str)
{
	int	i;
	int	n;
	int	negative;

	negative = 0;
	n = 0;
	i = 0;
	while (str[i] != '\0' && ft_is_space(str[i]))
		i++;
	while (str[i] != '\0' && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			negative = !negative;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		n *= 10;
		n += str[i] - '0';
		i++;
	}
	if (negative)
		n = -n;
	return (n);
}

/* int	main(void)
{
	char	*str;

	str = "0";
	printf("ft_atoi:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi(str));
	str = "1";
	printf("ft_atoi:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi(str));
	str = "10";
	printf("ft_atoi:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi(str));
	str = "15";
	printf("ft_atoi:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi(str));
	str = "1a";
	printf("ft_atoi:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi(str));
	str = "+1";
	printf("ft_atoi:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi(str));
	str = "-1";
	printf("ft_atoi:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi(str));
	str = "+-1";
	printf("ft_atoi:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi(str));
	str = "-+1";
	printf("ft_atoi:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi(str));
	str = "-+-1";
	printf("ft_atoi:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi(str));
	str = "  1a";
	printf("ft_atoi:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi(str));
	str = "  +1";
	printf("ft_atoi:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi(str));
	str = "  -1";
	printf("ft_atoi:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi(str));
	str = "  +-1";
	printf("ft_atoi:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi(str));
	str = "  -+1";
	printf("ft_atoi:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi(str));
	str = "  -+-1";
	printf("ft_atoi:\t\"%s\"\t-->\t%d\n", str, ft_atoi(str));
	str = "\t\n\v\f\r +1";
	printf("ft_atoi:\t\"\\t\\n\\v\\f\\r +1\"\t-->\t%d\n", ft_atoi(str));
	return (0);
} */
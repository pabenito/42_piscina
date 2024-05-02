/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 07:26:09 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/05 10:45:29 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	pos_in_str(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != c)
		i++;
	if (str[i] == c)
		return (i);
	else
		return (-1);
}

int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

int	ft_is_space(char c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

int	is_valid_base(char *base)
{
	int	i;
	int	j;
	int	len;

	if (base == NULL)
		return (0);
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

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	n;
	int	negative;

	if (!is_valid_base(base))
		return (0);
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
	while (str[i] != '\0' && pos_in_str(str[i], base) != -1)
	{
		n = n * str_len(base) + pos_in_str(str[i], base);
		i++;
	}
	if (negative)
		n = -n;
	return (n);
}

int main(void)
{
	char *str;
	char *base;

	base = "0123456789";
	str = "0";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi_base(str, base));
	str = "1";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi_base(str, base));
	str = "10";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi_base(str, base));
	str = "15";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi_base(str, base));
	str = "1a";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi_base(str, base));
	str = "+1";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi_base(str, base));
	str = "-1";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi_base(str, base));
	str = "+-1";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi_base(str, base));
	str = "-+1";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi_base(str, base));
	str = "-+-1";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi_base(str, base));
	str = "  1a";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi_base(str, base));
	str = "  +1";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi_base(str, base));
	str = "  -1";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi_base(str, base));
	str = "  +-1";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi_base(str, base));
	str = "  -+1";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\n", str, ft_atoi_base(str, base));
	str = "  -+-1";
	printf("ft_atoi_base:\t\"%s\"\t-->\t%d\n", str, ft_atoi_base(str, base));
	str = "\t\n\v\f\r +1";
	printf("ft_atoi_base:\t\"\\t\\n\\v\\f\\r +1\"\t-->\t%d\n", ft_atoi_base(str,
			base));
	base = "_|";
	str = "\t\n\v\f\r +|_|";
	printf("ft_atoi_base:\t\"\\t\\n\\v\\f\\r +|_|\"\t-->\t%d\n",
		ft_atoi_base(str, base));
	base = "01";
	str = "1011";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\t(Expected: 11)\n", str,
		ft_atoi_base(str, base));
	base = "0123456789ABCDEF";
	str = "-1A3";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\t(Expected: -419)\n", str,
		ft_atoi_base(str, base));
	base = "0123456789";
	str = " \t\n\r\v\f--++-43";
	printf("ft_atoi_base:\t\" \\t\\n\\r\\v\\f--++-43\"\t\t-->\t%d\t(Expected:-43)\n",
		ft_atoi_base(str, base));
	str = "19abc78";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\t(Expected: 19)\n", str,
		ft_atoi_base(str, base));
	base = "0";
	str = "1011";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\t(Expected: 0)\n", str,
		ft_atoi_base(str, base));
	base = "01+";
	str = "1011";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\t(Expected: 0)\n", str,
		ft_atoi_base(str, base));
	base = "0123456789ABCDEF";
	str = "-1B2A";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\t(Expected: -6954)\n", str,
		ft_atoi_base(str, base));
	base = "0123456789";
	str = "3489";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\t(Expected: 3489)\n", str,
		ft_atoi_base(str, base));
	base = "01";
	str = "";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\t(Expected: 0)\n", str,
		ft_atoi_base(str, base));
	base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	base = "01";
	str = "1101";
	printf("ft_atoi_base:\t\"%s\"\t\t-->\t%d\t(Expected: 13)\n", str,
		ft_atoi_base(str, base));
	base = "1";
	str = "10";
	printf("ft_atoi_base:\t\"%s\"\t(base: \"%s\")\t-->\t%d\t(Expected: 0)\n",
		str, base, ft_atoi_base(str, base));
	base = "110";
	str = "10";
	printf("ft_atoi_base:\t\"%s\"\t(base: \"%s\")\t-->\t%d\t(Expected: 0)\n",
		str, base, ft_atoi_base(str, base));
	base = "1+0";
	str = "10";
	printf("ft_atoi_base:\t\"%s\"\t(base: \"%s\")\t-->\t%d\t(Expected: 0)\n",
		str, base, ft_atoi_base(str, base));
	base = NULL;
	str = "10";
	printf("ft_atoi_base:\t\"%s\"\t(base: NULL)\t\t-->\t%d\t(Expected: 0)\n",
		str, ft_atoi_base(str, base));
	base = "";
	str = "10";
	printf("ft_atoi_base:\t\"%s\"\t(base: \"%s\")\t-->\t%d\t(Expected: 0)\n",
		str, base, ft_atoi_base(str, base));
	return (0);
}
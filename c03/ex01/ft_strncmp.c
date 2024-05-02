/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 08:12:52 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/03 17:47:13 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i] && i < n)
		i++;
	if (i == n)
		return (s1[i - 1] - s2[i - 1]);
	else
		return (s1[i] - s2[i]);
}

/* int	is_numeric(char c)
{
	return (c >= '0' && c <= '9');
}

int	char_to_int(char c)
{
	return (c - '0');
}

int	string_to_int(char *str)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (str[i] != '\0' && is_numeric(str[i]))
	{
		n *= 10;
		n += char_to_int(str[i]);
		i++;
	}
	if (str[i] == '\0')
		return (n);
	else
		return (-1);
}

int	main(int argc, char *argv[])
{
	if (argc != 4 || string_to_int(argv[3]) == -1)
	{
		printf("Error: You should provide two strings and a number");
		return (-1);
	}
	else
	{
		printf("Arguments: \"%s\" \"%s\" %d\nResult: %d\n", argv[1], argv[2],
			string_to_int(argv[3]), ft_strncmp(argv[1], argv[2],
				string_to_int(argv[3])));
		return (0);
	}
} */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 10:56:54 by pbenito-          #+#    #+#             */
/*   Updated: 2023/09/29 14:48:01 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
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
		printf("Arguments: \"%s\" \"%s\" %d\nResult: %s\n", argv[1], argv[2],
			string_to_int(argv[3]), ft_strncat(argv[1], argv[2],
				string_to_int(argv[3])));
		return (0);
	}
} */

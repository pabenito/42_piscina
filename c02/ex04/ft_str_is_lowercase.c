/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:06:54 by pbenito-          #+#    #+#             */
/*   Updated: 2023/09/28 19:37:51 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_str_is_lowercase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_lowercase(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* int	main(void)
{
	printf("%d\n", ft_str_is_lowercase(""));
	printf("%d\n", ft_str_is_lowercase("hellofellow"));
	printf("%d\n", ft_str_is_lowercase("hello fellow"));
	printf("%d\n", ft_str_is_lowercase("Hellofellow"));
	printf("%d\n", ft_str_is_lowercase("Hello fellow"));
	printf("%d\n", ft_str_is_lowercase("Hello Fellow ;-)"));
} */

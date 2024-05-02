/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 20:06:39 by pbenito-          #+#    #+#             */
/*   Updated: 2023/09/28 19:38:11 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char	uppercase_to_lowercase(char c)
{
	return (c - 'A' + 'a');
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_uppercase(str[i]))
			str[i] = uppercase_to_lowercase(str[i]);
		i++;
	}
	return (str);
}

/* int	main(void)
{
	char	*str;
	char	cpy[15];
	int		i;

	str = "Hello FeellOw";
	i = 0;
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	printf("%s", ft_strlowcase(cpy));
} */

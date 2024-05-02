/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:15:56 by pbenito-          #+#    #+#             */
/*   Updated: 2023/09/28 19:38:06 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

char	lowercase_to_uppercase(char c)
{
	return (c - 'a' + 'A');
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (is_lowercase(str[i]))
			str[i] = lowercase_to_uppercase(str[i]);
		i++;
	}
	return (str);
}

/* int	main(void)
{
	char	*str;
	char	cpy[15];
	int		i;

	str = "Hello fellow";
	i = 0;
	while (str[i] != '\0')
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	printf("%s", ft_strupcase(cpy));
} */

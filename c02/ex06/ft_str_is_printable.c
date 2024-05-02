/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 19:12:15 by pbenito-          #+#    #+#             */
/*   Updated: 2023/09/28 19:38:00 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}

int	ft_str_is_printable(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_printable(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* int	main(void)
{
	printf("%d\n", ft_str_is_printable(""));
	printf("%d\n", ft_str_is_printable("HelloFellow"));
	printf("%d\n", ft_str_is_printable("Hello Fellow"));
	printf("%d\n", ft_str_is_printable("Hello Fellow ;-)"));
	printf("%d\n", ft_str_is_printable("Hello Fellow ;-)\n"));
} */

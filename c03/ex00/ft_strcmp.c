/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 15:35:00 by pbenito-          #+#    #+#             */
/*   Updated: 2023/09/29 14:47:44 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

/* int	main(int argc, char *argv[])
{
	if (argc != 3)
	{
		printf("Error: You should provide two strings.");
		return (-1);
	}
	else
	{
		printf("%d", ft_strcmp(argv[1], argv[2]));
		return (0);
	}
} */

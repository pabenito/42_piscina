/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 09:26:11 by pbenito-          #+#    #+#             */
/*   Updated: 2023/09/29 10:53:49 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
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
		printf("Arguments: \"%s\" \"%s\"\nResult: %s\n", argv[1], argv[2],
			ft_strcat(argv[1], argv[2]));
		return (0);
	}
} */

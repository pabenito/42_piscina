/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:06:15 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/03 13:19:26 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;

	if (to_find[0] == '\0')
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != to_find[0] && str[i] != '\0')
			i++;
		j = 0;
		while (str[i + j] == to_find[j]
			&& str[i + j] != '\0' && to_find[j] != '\0')
			j++;
		if (to_find[j] == '\0')
			return (&str[i]);
		i += j;
	}
	return (NULL);
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
		printf("Arguments: \"%s\" \"%s\"\nResult: %ld\n", argv[1], argv[2],
			ft_strstr(argv[1], argv[2]) - argv[1]);
		return (0);
	}
} */

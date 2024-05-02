/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 12:10:50 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/05 07:26:03 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

/* int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		printf("Error: You must provide a string.\n");
		return (-1);
	}
	printf("\"%s\": %d\n", argv[1], ft_strlen(argv[1]));
	return (0);
} */
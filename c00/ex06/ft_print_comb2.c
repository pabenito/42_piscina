/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 18:26:14 by pbenito-          #+#    #+#             */
/*   Updated: 2023/09/21 17:15:24 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>

void	print_comb(char i[], char j[])
{
	char	str[8];
	int		len;

	len = 5;
	strcpy(str, i);
	strcat(str, " ");
	strcat(str, j);
	if (strcmp(i, "98") != 0 || strcmp(j, "99") != 0)
	{
		strcat(str, ", ");
		len += 2;
	}
	write(1, str, len);
}

void	ft_print_comb2(void)
{
	int		i;
	int		j;
	char	i_str[3];
	char	j_str[3];

	i = 0;
	j = 0;
	while (i < 100)
	{
		j = i + 1;
		while (j < 100)
		{
			sprintf(i_str, "%02d", i);
			sprintf(j_str, "%02d", j);
			print_comb(i_str, j_str);
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:50:35 by pbenito-          #+#    #+#             */
/*   Updated: 2023/09/24 08:18:36 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

void	ft_swap(int *arr, int i, int j)
{
	int	tmp;

	tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size / 2)
	{
		ft_swap(tab, i, size - 1 - i);
		i++;
	}
}

/*int	main(void)
{
	int	array[3];

	array[0] = 1;
	array[1] = 2;
	array[2] = 3;
	ft_rev_int_tab(array, 3);
	printf("%d%d%d", array[0], array[1], array[2]);
	return (0);
}*/

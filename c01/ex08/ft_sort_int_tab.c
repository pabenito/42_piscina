/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:00:32 by pbenito-          #+#    #+#             */
/*   Updated: 2023/09/24 08:20:51 by pbenito-         ###   ########.fr       */
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

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	min;

	i = 0;
	while (i < size - 1)
	{
		min = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[min])
				min = j;
			j++;
		}
		ft_swap(tab, i, min);
		i++;
	}
}

/*int	main(void)
{
	int	arr[4];

	arr[0] = 3;
	arr[1] = 1;
	arr[2] = 2;
	arr[3] = 0;
	ft_sort_int_tab(arr, 4);
	printf("%d%d%d%d", arr[0], arr[1], arr[2], arr[3]);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 09:07:28 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/12 13:52:30 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "free.h"

void	matrix_free(t_map map)
{
	int	row;

	row = 0;
	while (row < map.rows)
	{
		free(map.matrix[row]);
		row++;
	}
	free(map.matrix);
}

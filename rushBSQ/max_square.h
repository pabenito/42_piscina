/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_square.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:42:21 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/12 13:57:51 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAX_SQUARE_H
# define MAX_SQUARE_H

# include "map.h"

void	find_max_square_in_the_map(t_map map, t_square *max_square);
void	max_square_posible(t_map map, t_square *square);
int		is_a_posible_square(t_map map, t_square *square);

#endif
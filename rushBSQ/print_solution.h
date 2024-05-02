/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_solution.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:51:23 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/11 21:05:50 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_SOLUTION_H
# define PRINT_SOLUTION_H

# include <unistd.h>
# include "map.h"

void	print_map_with_max_square(t_map map, t_square max_square);

#endif
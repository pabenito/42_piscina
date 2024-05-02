/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:06:49 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/12 13:29:03 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include <fcntl.h>
# include <unistd.h>
# include "map.h"
# include "utils.h"
# include "read_extra.h"
# include "malloc.h"

# define MAX_ROWS_DIGITS 10

int	fill_matrix_from_str(t_map *map, char *buffer);
int	read_map_info_characters(t_map *map, char buffer[], int index);
int	read_map_info(int file, t_map *map, int *info_line_length);
int	read_map_matrix(int file, t_map *map, int info_line_length);
int	read_map(char *file_path, t_map *map);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_extra.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 14:04:13 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/12 13:10:59 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_EXTRA_H
# define READ_EXTRA_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include "map.h"
# include "utils.h"

int	is_valid_input_char(char c, t_map *map);
int	map_to_str_pos(int row, int col, t_map *map);
int	reopen_file(char *file_path, int *file);
int	count_line_length(char buffer[], int index, ssize_t size);
int	count_matrix_columns(int file, t_map *map, int info_line_length);

#endif
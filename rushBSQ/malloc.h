/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:45:54 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/10 16:31:37 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdlib.h>

int	malloc_buffer(char **buffer, int rows, int cols);
int	malloc_matrix(char ***matrix, int rows, int cols);

#endif
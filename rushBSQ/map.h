/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 08:59:53 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/12 13:08:45 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# define ERROR -1

typedef struct s_map	t_map;
struct					s_map
{
	int					rows;
	int					cols;
	char				empty;
	char				obstacle;
	char				full;
	char				**matrix;
};

typedef struct s_square	t_square;
struct					s_square
{
	int					row;
	int					col;
	int					side;
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 23:27:43 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/08 23:39:53 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#define FILE "numbers.dict"

void	free_array_lines(t_line *array, int size);
void	free_array_numbers(struct s_number *array, int size);
t_line	*read_file(char *file_path, int lines);
char 	**get_trios(char *input, int	*num_trios);
int	count_lines(char *file_path);

typedef struct s_line	*t_line;
struct					s_line
{
	char				*number;
	char				*str;
};

struct					s_number
{
	int					digits;
	int					number;
	char				*number_str;
	char				*str;
};

void	frees(t_line *lines_dict, struct s_number *clean_dict, int lines,
		int size)
{
	if (lines_dict != NULL && lines > 0)
		free_array_lines(lines_dict, lines);
	if (clean_dict != NULL && size > 0)
		free_array_numbers(clean_dict, size);
}

int	error(t_line *lines_dict, struct s_number *clean_dict, int lines, int size)
{
	frees(lines_dict, clean_dict, lines, size);
	write(1, "Error\n", 6);
	return (-1);
}

int	main(int argc, char *argv[])
{
	t_line			*lines_dict;
	struct s_number	*clean_dict;
	int				lines;
	char			**trios;
	int				size;
	int				num_trios;

	lines_dict = NULL;
	clean_dict = NULL;
	lines = -1;
	size = -1;
	if (argc < 2 || argc > 3)
		return (error(lines_dict, clean_dict, lines, size));
	if (argc == 2)
	{
		lines = count_lines(FILE);
		if (lines == -1)
			return (error(lines_dict, clean_dict, lines, size));
		lines_dict = read_file(FILE, lines);
		if (lines_dict == NULL)
			return (error(lines_dict, clean_dict, lines, size));
	}
	else
	{
		lines = count_lines(FILE);
		if (lines == -1)
			return (error(lines_dict, clean_dict, lines, size));
		lines_dict = read_file(FILE, lines);
		if (lines_dict == NULL)
			return (error(lines_dict, clean_dict, lines, size));
	}
	clean_dict = clear_numbers(lines_dict, lines, &size);
	trios = get_trios(argv[1], &num_trios);
	if (print_number(trios, clean_dict, size, num_trios))
		return (error(lines_dict, clean_dict, lines, size));
	frees(lines_dict, clean_dict, lines, size);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 14:08:21 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/08 23:41:09 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUF_SIZE 128

char	*str_copy(char *dest, char *src);
int	str_cmp(char *s1, char *s2);
void	put_str(char *str);
int	str_length(char *str);
int	str_number_to_int(char *number);

typedef struct s_line	*t_line;
struct	s_line
{
	char	*number;
	char	*str;
};

struct	s_number
{
	int		digits;
	int		number;
	char	*number_str;
	char	*str;
};

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	is_printable(char c)
{
	return (c >= ' ' && c <= '~');
}

int	is_valid_line(t_line line)
{
	int	i;
	int	n;

	if (line == NULL)
		return (0);
	n = str_number_to_int(line->number);
	if (n >= 0 && n <= 20)
		return (1);
	if (!is_digit((line->number)[0]) || (line->number)[0] == '0')
		return (0);
	i = 1;
	while (line->number[i] != '\0' && line->number[i] == '0')
		i++;
	if (line->number[i] != '\0')
		return (0);
	return (1);
}

int	count_valid_lines(t_line *array, int size)
{
	int	i;
	int	valid_count;

	valid_count = 0;
	i = 0;
	while (i < size)
	{
		if (is_valid_line(array[i]))
			valid_count++;
		i++;
	}
	return (valid_count);
}

struct s_number	line_to_number_dict(t_line line)
{
	struct s_number	number;

	number.digits = str_length(line->number);
	number.number_str = (char *)malloc((number.digits + 1) * sizeof(char));
	number.str = (char *)malloc(str_length(line->str));
	str_copy(number.number_str, line->number);
	str_copy(number.str, line->str);
	number.number = str_number_to_int(number.number_str);
	return (number);
}

struct s_number	*clear_numbers(t_line *array, int size, int *valid_count)
{
	struct s_number	*dict;
	int				dict_index;
	int				i;

	*valid_count = count_valid_lines(array, size);
	dict = (struct s_number *)malloc(*valid_count * sizeof(struct s_number));
	dict_index = 0;
	i = 0;
	while (i < size)
	{
		if (is_valid_line(array[i]))
		{
			dict[dict_index] = line_to_number_dict(array[i]);
			dict_index++;
		}
		i++;
	}
	return (dict);
}

int	count_lines(char *file_path)
{
	int		file;
	char	buffer[BUF_SIZE];
	ssize_t	nbytes;
	int		lines;
	int		i;

	lines = 0;
	file = open(file_path, O_RDONLY);
	if (file == -1)
		return (-1);
	nbytes = read(file, buffer, BUF_SIZE);
	while (nbytes > 0)
	{
		i = 0;
		while (i < nbytes)
		{
			if (buffer[i] == '\n')
				lines++;
			i++;
		}
		nbytes = read(file, buffer, BUF_SIZE);
	}
	close(file);
	return (lines + 1);
}

// \n included
int	count_line_length(char buffer[], int index, ssize_t size)
{
	int	i;

	i = 0;
	while (index + i < size)
	{
		if (buffer[index + i] == '\n')
			return (i + 1);
		i++;
	}
	return (-1);
}

void	copy_truncated_to_init(char *buffer, int index, int size)
{
	int	i;

	i = 0;
	while (i + index < size)
	{
		buffer[i] = buffer[index + i];
		i++;
	}
}

t_line	process_line(char *buffer, int index, int length)
{
	t_line	line;
	int		i;
	int		j;

	line = (t_line)malloc(sizeof(struct s_line));
	*line = (struct s_line){NULL, NULL};
	if (!is_digit(buffer[index]))
		return (NULL);
	line->number = (char *)malloc(length * sizeof(char));
	line->str = (char *)malloc(length * sizeof(char));
	i = 0;
	while (i < length && is_digit(buffer[index + i]))
	{
		line->number[i] = buffer[index + i];
		i++;
	}
	while (i < length && buffer[index + i] == ' ')
		i++;
	if (i < length && buffer[index + i] != ':')
		return (NULL);
	i++;
	while (i < length && buffer[index + i] == ' ')
		i++;
	j = 0;
	while (i < length && is_printable(buffer[index + i]))
	{
		line->str[j] = buffer[index + i];
		j++;
		i++;
	}
	if (i >= length || buffer[index + i] != '\n')
		return (NULL);
	return (line);
}

t_line	*read_file(char *file_path, int lines)
{
	char	buffer[BUF_SIZE];
	t_line	*dict;
	int		nbytes;
	int		file;
	int		line;
	int		size;
	int		line_length;
	int		truncated_length;
	int		i;

	line = 0;
	if (lines == -1)
		return (NULL);
	dict = (t_line *)malloc(lines * sizeof(t_line *));
	file = open(file_path, O_RDONLY);
	if (file == -1)
		return (NULL);
	nbytes = read(file, buffer, BUF_SIZE);
	size = nbytes;
	while (nbytes > 0)
	{
		i = 0;
		line_length = count_line_length(buffer, i, size);
		while (line_length > 0)
		{
			dict[line] = process_line(buffer, i, line_length);
			line++;
			i += line_length;
			line_length = count_line_length(buffer, i, size);
		}
		copy_truncated_to_init(buffer, i, size);
		truncated_length = size - i;
		nbytes = read(file, &buffer[truncated_length], i);
		size = truncated_length + nbytes;
		if (size < BUF_SIZE)
		{
			buffer[size] = '\n';
			size++;
		}
	}
	close(file);
	return (dict);
}

int num_trio(int n)
{
	if (n % 3 == 0)
		return (n / 3);
	else
		return (n / 3 + 1);
}

int trio_position(int n)
{
	return (2 - n % 3);	
}

char **get_trios(char *input, int	*num_trios)
{
	int		digits;
	char	**trios;
	int		i;
	int		trio_index;
	int		index_in_trio;

	digits = str_length(input);
	*num_trios = num_trio(digits);
	trios = (char **)malloc(*num_trios * sizeof(char *));
	i = 0;
	while (i < *num_trios)
	{
		trios[i] = (char *)malloc(4 * sizeof(char));
		i++;
	}
	i = 0;
	while (i < digits)
	{
		trio_index = num_trio(digits - i) - 1;
		index_in_trio = trio_position(digits - i - 1);
		trios[trio_index][index_in_trio] = input[i];
		i++;
	}
	i = 0;
	while (!is_digit(trios[*num_trios - 1][i]))
	{
		trios[*num_trios - 1][i] = '0';
		i++;
	}	
	i = 0;
	while (i < *num_trios)
	{
		trios[i][3] = '\0';
		i++;
	}
	return (trios);
}
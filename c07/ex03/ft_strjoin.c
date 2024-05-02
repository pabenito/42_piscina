/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 12:28:13 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/12 19:23:52 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

int	total_chars(char **strs, int size)
{
	int	i;
	int	total_chars;

	total_chars = 0;
	i = 0;
	while (i < size)
	{
		if (strs[i] != NULL)
			total_chars += ft_strlen(strs[i]);
		i++;
	}
	return (total_chars);
}

char	*malloc_str(int size, char **strs, char *sep)
{
	char	*str;
	int		total_strs_chars;
	int		sep_length;
	int		malloc_length;

	if (size == 0)
		return (NULL);
	total_strs_chars = total_chars(strs, size);
	sep_length = ft_strlen(sep);
	malloc_length = total_strs_chars + sep_length * (size - 1) + 1;
	str = (char *)malloc(malloc_length * sizeof(char));
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;

	str = malloc_str(size, strs, sep);
	str[0] = '\0';
	i = 0;
	while (i < size)
	{
		ft_strcat(str, strs[i]);
		ft_strcat(str, sep);
		i++;
	}
	return (str);
}

/* int	main(void)
{
	char	*strs[4];
	char	*sep;

	strs[0] = "Hey,";
	strs[1] = "how";
	strs[2] = "are";
	strs[3] = "you?";
	sep = " ";
	printf("%s\n", ft_strjoin(4, strs, sep));
	return (0);
} */

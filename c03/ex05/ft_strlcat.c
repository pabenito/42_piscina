/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 12:03:18 by pbenito-          #+#    #+#             */
/*   Updated: 2023/10/03 18:56:51 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

unsigned int	str_len(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

unsigned int	min(unsigned int a, unsigned int b)
{
	if (a > b)
		return (b);
	else
		return (a);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dest_len;
	unsigned int	src_len;

	dest_len = str_len(dest);
	src_len = str_len(src);
	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (src_len + min(size, dest_len));
}

/* char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	main(int argc, char *argv[])
{
	char	dest[10];
	char	src[10];
	int		n;

	n = 0;
	while (n < 10)
	{
		printf("Size: %d\n", n);
		ft_strcpy(dest, "Hola");
		ft_strcpy(src, "ab");
		printf("Result: \"%s\" %d\n", dest, ft_strlcat(dest, src, n));
		ft_strcpy(dest, "Hola");
		ft_strcpy(src, "ab");
		printf("Result: \"%s\" %ld\n", dest, strlcat(dest, src, n));
		n++;
	}
	return (0);
} */

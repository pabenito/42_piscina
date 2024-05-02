/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbenito- <pbenito-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 13:16:07 by pbenito-          #+#    #+#             */
/*   Updated: 2023/09/23 19:26:49 by pbenito-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a - *div * b;
}

/*int	main(void)
{
	int	div;
	int	mod;

	ft_div_mod(5, 2, &div, &mod);
	printf("div:%d; mod:%d", div, mod);
	return (0);
}*/

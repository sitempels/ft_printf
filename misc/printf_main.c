/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:24:45 by stempels          #+#    #+#             */
/*   Updated: 2024/12/20 13:37:06 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char	*e;
	int	*p;
	int	a;

	p = &a;
	e = NULL;

	printf("\n----- no argument test -----\n\n");
	printf("valeur ft_printf: %d\n", ft_printf("Ceci est un test \n"));
	printf("valeur    printf: %d\n", printf("Ceci est un test \n"));
	printf("\n----- no argument test -----\n");

	printf("\n----- wrong argument test -----\n");
	printf("valeur ft_printf: %d\n", ft_printf("Ceci est %YY un %W %Z test \n"));
//	printf("valeur    printf: %d\n", printf("Ceci est %Y un test \n"));
	printf("\n----- wrong argument test -----\n");
	
	printf("\n----- argument test -----\n\n");
	printf("valeur ft_printf: %d\n", ft_printf("Ceci %c %s %d %i %u %u %x %X %p %p \n", 'a', "bcd", -2147483647, 2147483647, 0, 294967295, 16, 103, p, e));
	printf("valeur    printf: %d\n",    printf("Ceci %c %s %d %i %u %u %x %X %p %p \n", 'a', "bcd", -2147483647, 2147483647, 0, 294967295, 16, 103, p, e));
	printf("\n----- argument test -----\n");
	return (0);
}

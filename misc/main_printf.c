/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 13:24:45 by stempels          #+#    #+#             */
/*   Updated: 2025/01/13 15:00:11 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
/*	char	*e;
	int	*p;
	int	a;

	p = &a;
	e = NULL;

	printf("\n----- no argument test -----\n\n");
	printf("valeur ft_printf: %d\n", ft_printf(NULL));
//	printf("valeur    printf: %d\n", printf(NULL));
	printf("\n----- no argument test -----\n\n");

	printf("\n----- 1 argument test -----\n\n");
	printf("valeur ft_printf: %d\n", ft_printf("Ceci est un ft_printf\n"));
	printf("valeur    printf: %d\n", printf("Ceci est un st_printf\n"));
	printf("\n----- 1 argument test -----\n");

	printf("\n----- wrong argument test -----\n\n");
	printf("valeur ft_printf: %d\n", ft_printf("Ceci est %YY un %W %Z test \n"));
//	printf("valeur    printf: %d\n", printf("Ceci est %Y un test \n"));
	printf("\n----- wrong argument test -----\n");
*/	
	printf("\n----- argument test -----\n\n");
	printf("valeur ft_printf: %d\n", ft_printf("Ceci %p %p\n", LONG_MIN, LONG_MAX));
	printf("valeur ft_printf: %d\n", ft_printf("Ceci %p %p\n", ULONG_MAX, -ULONG_MAX));
	printf("valeur    printf: %d\n", printf("Ceci %p %p\n", LONG_MIN, LONG_MAX));
	printf("valeur    printf: %d\n", printf("Ceci %p %p\n", ULONG_MAX, -ULONG_MAX));
/*	printf("valeur ft_printf: %d\n", ft_printf("Ceci c %c\n", 'a'));
	printf("valeur ft_printf: %d\n", ft_printf("Ceci s %s\n", "bcd"));
	printf("valeur ft_printf: %d\n", ft_printf("Ceci d %d\n", -2147483648));
	printf("valeur ft_printf: %d\n", ft_printf("Ceci d %d\n", -1));
	printf("valeur ft_printf: %d\n", ft_printf("Ceci d %d\n", 0));
	printf("valeur ft_printf: %d\n", ft_printf("Ceci d %d\n", 1));
	printf("valeur ft_printf: %d\n", ft_printf("Ceci i %i\n", 2147483647));
	printf("valeur ft_printf: %d\n", ft_printf("Ceci u %u\n", 0));
	printf("valeur ft_printf: %d\n", ft_printf("Ceci u %u\n", 4294967295));
	printf("valeur ft_printf: %d\n", ft_printf("Ceci x %x\n", 16));
	printf("valeur ft_printf: %d\n", ft_printf("Ceci X %X\n", 'j'));
	printf("valeur ft_printf: %d\n", ft_printf("Ceci p %p\n", p));
	printf("valeur ft_printf: %d\n", ft_printf("Ceci p %p\n", e));
	printf("valeur ft_printf: %d\n", ft_printf("Ceci %c %s %d %i %u %u %x %X %p %p\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
	printf("valeur ft_printf: %d\n", ft_printf(NULL));
	printf("valeur    printf: %d\n", printf("Ceci %c\n", 'a'));
	printf("valeur    printf: %d\n", printf("Ceci %s\n", "bcd"));
	printf("valeur    printf: %d\n", printf("Ceci %d\n", (int)-2147483648));
	printf("valeur    printf: %d\n", printf("Ceci %d\n", (int)-1));
	printf("valeur    printf: %d\n", printf("Ceci %d\n", (int)0));
	printf("valeur    printf: %d\n", printf("Ceci %d\n", (int)1));
	printf("valeur    printf: %d\n", printf("Ceci %i\n", (int)2147483647));
	printf("valeur    printf: %d\n", printf("Ceci %u\n", 0));
	printf("valeur    printf: %d\n", printf("Ceci %u\n", (unsigned)4294967295));
	printf("valeur    printf: %d\n", printf("Ceci %x\n", 16));
	printf("valeur    printf: %d\n", printf("Ceci %X\n", 'j'));
	printf("valeur    printf: %d\n", printf("Ceci %p\n", p));
	printf("valeur    printf: %d\n", printf("Ceci %p\n", e));
	printf("valeur    printf: %d\n",    printf("Ceci %c %s %d %i %u %u %x %X %p %p\n", NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL));
	printf("valeur    printf: %d\n", printf(NULL));*/
	printf("\n----- argument test -----\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:02:16 by stempels          #+#    #+#             */
/*   Updated: 2024/12/13 11:30:41 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	main(void)
{
	void	*a = 1;
	void	*b = "Hello";
	
	printf("%lu \n", strlen(a));
	printf("%lu \n", strlen(b));
	return (0);
}

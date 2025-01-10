/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 11:38:14 by stempels          #+#    #+#             */
/*   Updated: 2025/01/08 15:08:31 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
*/

size_t	ft_charlen(void)
{
	return (1);
}

/*size_t	ft_lenstr(char **str)
{
	size_t	i;

	i = 0;
	while (str[0][i])
		i++;
	return (i);
}
*/
size_t	ft_sintlen(void *argument, t_format *format)
{
	size_t		i;
	ssize_t		n;
	ssize_t		b_len;
	int			sign;

	b_len = (ssize_t)ft_strlen(format->type.base);
	sign = 0;
	n = (ssize_t) (int *) argument;
	i = 0;
	if (n < 0)
	{
		sign = 1;
		n = n * -1;
	}
	while (n > (b_len - 1))
	{
		n = n / b_len;
		i++;
	}
	return (++i + sign);
}

size_t	ft_uintlen(void *argument, t_format *format)
{
	size_t		n;
	size_t		i;
	size_t		b_len;

	b_len = ft_strlen(format->type.base);
	if (format->type.type == 'p')
		n = *(size_t *) (uintptr_t *) &argument;
	else
		n = (size_t) (unsigned int *) argument;
	i = 0;
	while (n > (b_len - 1))
	{
		n = n / b_len;
		i++;
	}
	if (format->type.type == 'p')
		i = i + 2;
	return (++i);
}

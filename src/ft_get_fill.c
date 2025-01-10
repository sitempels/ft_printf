/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fill.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:40:49 by stempels          #+#    #+#             */
/*   Updated: 2025/01/08 12:56:13 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_char(void *argument, t_format *format, size_t len)
{
	char	arg;

	arg = *(char *)argument;
	format->res[len - 1] = arg;
}

void	fill_str(void **argument, t_format *format, size_t len)
{
	char	*arg;
	size_t	i;

	arg = (char *)*argument;
	i = 0;
	while (i < len)
	{
		format->res[i] = arg[i];
		i++;
	}
}

void	fill_sint(void **argument, t_format *format, size_t len)
{
	ssize_t		i;
	ssize_t		arg;
	ssize_t		base;

	arg = (size_t) *(int *) argument;
	base = ft_strlen(format->type.base);
	i = len - 1;
	if (arg < 0)
	{
		arg = arg * -1;
		format->res[0] = '-';
	}
	while (arg > (base - 1))
	{
		format->res[i] = format->type.base[arg % base];
		arg = arg / base;
		i--;
	}
	format->res[i] = (arg % base) + 48;
}

void	fill_uint(void **argument, t_format *format, size_t len)
{
	size_t	arg;
	ssize_t	i;
	size_t	base;

	if (format->type.type == 'X')
		format->type.base = BASE_X16;
	arg = *(size_t *) argument;
	base = ft_strlen(format->type.base);
	i = len - 1;
	if (format->type.type == 'p')
	{
		format->res[0] = '0';
		format->res[1] = 'x';
	}
	while (arg > (base - 1))
	{
		format->res[i] = format->type.base[(arg % base)];
		arg = arg / base;
		i--;
	}
	format->res[i] = format->type.base[(arg % base)];
	i = 0;
}

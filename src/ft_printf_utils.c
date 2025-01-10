/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 10:23:47 by stempels          #+#    #+#             */
/*   Updated: 2025/01/02 12:17:11 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_free(t_format *format)
{
	if (format->type.type != 0)
	{
		free(format->res);
	}
	format->type.type = 0;
	return ;
}

t_tprint	fill_struct(char *base, char type, size_t (*len)(), void (*fill)())
{
	t_tprint	struct_to_fill;

	struct_to_fill.base = base;
	struct_to_fill.type = type;
	struct_to_fill.get_len = len;
	struct_to_fill.get_fill = fill;
	return (struct_to_fill);
}

char	*fill_array(char *dst, char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

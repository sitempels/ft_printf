/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:12:39 by stempels          #+#    #+#             */
/*   Updated: 2025/01/09 12:16:44 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	t_format	format;
	int		printed;

	va_start(arg, str);
	if (str == NULL)
	{
		va_end (arg);
		return (-1);
	}
	printed = 0;
	format.res = NULL;
	format.type = fill_struct(NULL, 0, NULL, NULL);
	str_prs(&arg, (char *)str, &format, &printed);
	va_end (arg);
	return (printed);
}

int	str_prs(va_list *arg, char *str, t_format *format, int *printed)
{
	ssize_t		i;
	size_t		buffer;

	i = -1;
	while (str[++i])
	{
		buffer = 1;
		format->res = (char *)&str[i];
		if (str[i] == '%' && is_format(str, format, &i))
		{
			buffer = get_print(va_arg(*arg, void *), format);
			if (!format->res)
				return (-1);
		}
		write (1, format->res, buffer);
		ft_free(format);
		*printed = *printed + buffer;
	}
	return (0);
}

int	is_format(const char *str, t_format *format, ssize_t *place)
{
	size_t		i;
	size_t		j;
	char		typeset[8];

	i = *place + 1;
	fill_array(typeset, "csdiuxXp", 8);
	j = 0;
	while (typeset[j])
	{
		if (typeset[j] == str[i])
		{
			ft_init_type(str[i], format);
			*place = i;
			return (1);
		}
		j++;
	}
	*place = i - 1;
	return (0);
}

t_format	ft_init_type(char type, t_format *format)
{
	t_tprint	type_print;

	if (type == 'c')
		type_print = fill_struct(NULL, type, ft_charlen, fill_char);
	else if (type == 's')
		type_print = fill_struct(NULL, type, ft_strlen, fill_str);
	else if (type == 'd' || type == 'i')
		type_print = fill_struct(BASE_10, type, ft_sintlen, fill_sint);
	else if (type == 'u')
		type_print = fill_struct(BASE_10, type, ft_uintlen, fill_uint);
	else if (type == 'x' || type == 'X' || type == 'p')
		type_print = fill_struct(BASE_16, type, ft_uintlen, fill_uint);
	else
		type_print = fill_struct(NULL, 0, NULL, NULL);
	format->res = &type;
	format->type = type_print;
	return (*format);
}

size_t	get_print(void *argument, t_format *format)
{
	size_t			len;

	if (!argument && format->type.type == 'p')
	{
		format->res = "(nil)";
		format->type.type = 0;
		return (5);
	}
	len = format->type.get_len(argument, format);
	format->res = (char *) malloc (sizeof(char) * len + 1);
	if (!format->res)
		return (-1);
	format->res[len] = '\0';
	format->type.get_fill(&argument, format, len);
	return (len);
}

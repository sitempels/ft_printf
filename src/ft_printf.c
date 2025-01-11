/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:12:39 by stempels          #+#    #+#             */
/*   Updated: 2025/01/11 18:11:54 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list		arg;
	int		printed;

	va_start(arg, str);
	if (str == NULL)
	{
		va_end (arg);
		return (-1);
	}
	printed = 0;
	str_prs(arg, (char *)str, &printed);
	va_end (arg);
	return (printed);
}

int	str_prs(va_list arg, char *str, int *printed)
{
	char		*res;
	size_t		i;
	size_t		buffer;

	i = 0;
	while (str[i])
	{
		buffer = 1;
		res = &str[i];
		if (str[i] == '%' && is_format(str, &i))
		{
			buffer = get_print(arg, str[i]);
			/*if (!format->res)
				return (-1);*/
		}
		else
			write (1, res, buffer);
		*printed = *printed + buffer;
		i++;
	}
	return (0);
}

int	is_format(char *str, size_t *place)
{
	size_t		i;
	size_t		j;
	char		typeset[8];

	i = *place + 1;
	fill_array(typeset, FORMAT, ft_strlen(FORMAT));
	j = 0;
	while (typeset[j])
	{
		if (typeset[j] == str[i])
		{
			*place = i;
			return (1);
		}
		j++;
	}
	*place = i - 1;
	return (0);
}


size_t	get_print(va_list arg, char type)
{
	size_t	buffer;

	buffer = 0;
	if (type == 'c')
		buffer = ft_putchar_fd(va_arg(arg, int), 1);
	else if (type == 's')
		buffer = ft_putstr_fd(va_arg(arg, char *), 1);
	else if (type == 'd' || type == 'i')
		bu = ft_putnbr_base_fd((long long)va_arg(arg, int), BASE_10, 1);
	else if (type == 'u')
		buffer = ft_putnbr_base_fd(va_arg(arg, long long), BASE_10, 1);
	else if (type == 'x')
		buffer = ft_putnbr_base_fd(va_arg(arg, long long), BASE_16, 1);
	else if (type == 'X')
		buffer = ft_putnbr_base_fd(va_arg(arg, long long), BASE_X16, 1);
	else if (type == 'p')
		buffer += ft_putnbr_base_fd((long long)va_arg(arg, uintptr_t), BASE_16, 1);
	else
		return (-1);
	return (buffer);
}

/*size_t	get_print(void *argument, t_format *format)
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
}*/

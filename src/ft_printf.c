/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:12:39 by stempels          #+#    #+#             */
/*   Updated: 2025/01/13 16:09:00 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	str_prs(va_list arg, char *str, int *printed, int fd);
static int	is_format(char *str, size_t *place);
static int	get_print(va_list arg, char type, int fd);

int	ft_printf(const char *str, ...)
{
	int		fd;
	int		printed;
	va_list	arg;

	fd = 1;
	va_start(arg, str);
	printed = 0;
	if (!str)
		return (-1);
	str_prs(arg, (char *)str, &printed, fd);
	va_end (arg);
	return (printed);
}

static int	str_prs(va_list arg, char *str, int *printed, int fd)
{
	int		buffer;
	char	*res;
	size_t	i;

	i = 0;
	while (str[i])
	{
		buffer = 1;
		res = &str[i];
		if (str[i] == '%' && is_format(str, &i))
		{
			buffer = get_print(arg, str[i], fd);
			if (buffer < 0)
				return (-1);
		}
		else
			write (1, res, buffer);
		*printed = *printed + buffer;
		i++;
	}
	return (buffer);
}

static int	is_format(char *str, size_t *place)
{
	char		typeset[9];
	size_t		i;
	size_t		j;

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

static int	get_print(va_list arg, char type, int fd)
{
	int	b;

	b = 0;
	if (type == 'c')
		b = ft_putchar_fd(va_arg(arg, int), fd);
	else if (type == 's')
		b = get_s(va_arg(arg, char *), fd);
	else if (type == 'd' || type == 'i')
		b = ft_putnbr_bfd((long long)va_arg(arg, int), BA_10, fd);
	else if (type == 'u')
		b = ft_putnbr_bfd((long long)va_arg(arg, unsigned), BA_10, fd);
	else if (type == 'x')
		b = ft_putnbr_bfd((long long)va_arg(arg, unsigned), BA_16, fd);
	else if (type == 'X')
		b = ft_putnbr_bfd((long long)va_arg(arg, unsigned), BA_X16, fd);
	else if (type == 'p')
		b = get_p(va_arg(arg, unsigned long long), BA_16, fd);
	else
		b = write(fd, "%", 1);
	return (b);
}

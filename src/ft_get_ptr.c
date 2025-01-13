/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:40:28 by stempels          #+#    #+#             */
/*   Updated: 2025/01/13 16:01:49 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_bfd(unsigned long long nbr, char *base, int fd);
static int	wptr(unsigned long long nbr, char *base, size_t b_len, int fd);

int	get_p(unsigned long long arg, char *base, int fd)
{
	size_t	writed;

	writed = 0;
	if (arg == 0)
		return (write(fd, "(nil)", 5));
	writed += write(fd, "0x", 2);
	return (writed += ft_putptr_bfd(arg, base, fd));
}

static int	ft_putptr_bfd(unsigned long long nbr, char *base, int fd)
{
	int		writed;
	size_t	base_len;

	if (fd < 0)
		return (-1);
	writed = 0;
	base_len = 0;
	base_len = ft_strlen(base);
	writed += wptr(nbr, base, base_len, fd);
	return (writed);
}

static int	wptr(unsigned long long nbr, char *base, size_t b_len, int fd)
{
	int	writed;
	int	printed;

	writed = 0;
	printed = 0;
	if (nbr > b_len - 1)
		printed += wptr(nbr / b_len, base, b_len, fd);
	if (printed == -1)
		return (-1);
	writed = ft_putchar_fd(base[nbr % b_len], fd);
	if (writed == -1)
		return (-1);
	printed = printed + writed;
	return (printed);
}

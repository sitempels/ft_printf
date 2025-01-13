/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:37:46 by stempels          #+#    #+#             */
/*   Updated: 2025/01/13 16:00:45 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	writing_nbr_fd(long long nbr, char *base, ssize_t b_len, int fd);

int	ft_putnbr_bfd(long long nbr, char *base, int fd)
{
	int		writed;
	size_t	base_len;

	if (fd < 0)
		return (-1);
	writed = 0;
	base_len = 0;
	base_len = ft_strlen(base);
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		nbr *= -1;
		writed++;
	}
	writed += writing_nbr_fd(nbr, base, base_len, fd);
	return (writed);
}

static int	writing_nbr_fd(long long nbr, char *base, ssize_t b_len, int fd)
{
	int	writed;
	int	printed;

	writed = 0;
	printed = 0;
	if (nbr > b_len - 1)
		printed += writing_nbr_fd(nbr / b_len, base, b_len, fd);
	if (printed == -1)
		return (-1);
	writed = ft_putchar_fd(base[nbr % b_len], fd);
	if (writed == -1)
		return (-1);
	printed = printed + writed;
	return (printed);
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

int	get_s(char *arg, int fd)
{
	if (arg == NULL)
		return (write(fd, "(null)", 6));
	return (ft_putstr_fd(arg, fd));
}

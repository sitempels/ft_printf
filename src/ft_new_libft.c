/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_libft.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 14:37:46 by stempels          #+#    #+#             */
/*   Updated: 2025/01/11 18:07:25 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	writing_nbr_fd(long long nbr, char *base, ssize_t b_len, int fd);

size_t	ft_putnbr_base_fd(long long nbr, char *base, int fd)
{
	size_t	writed;
	size_t	base_len;

//	secure_printf(nbr);
	if (fd < 0)
		return (-1);
	writed = 0;
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

static size_t	writing_nbr_fd(long long nbr, char *base, ssize_t b_len, int fd)
{
	ssize_t	writed;
	ssize_t printed;

	writed = 0;
	printed = 0;
	if (nbr > b_len - 1)
		printed += writing_nbr_fd(nbr / b_len, base, b_len, fd);
	if (printed == -1)
		return (-1);
	writed = ft_putchar_fd(base[nbr % b_len], 1);
	if (writed == -1)
		return (-1);
	printed = printed + writed;
	return (printed);
}

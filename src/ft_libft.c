/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 10:55:45 by stempels          #+#    #+#             */
/*   Updated: 2025/01/20 11:00:52 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_putstr_fd(char *s, int fd)
{
	int		i;
	size_t	writed;

	i = 0;
	writed = 0;
	if (!s || fd < 0)
		return (-1);
	while (s[i])
	{
		writed += write(fd, &s[i], 1);
		i++;
	}
	return (writed);
}

size_t	ft_putchar_fd(char c, int fd)
{
	size_t	writed;

	writed = 0;
	writed += write(fd, &c, 1);
	return (writed);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 14:57:02 by stempels          #+#    #+#             */
/*   Updated: 2024/12/13 11:32:18 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_print_char(int ui, void **format)
{
	size_t	len;

	len = 1;
	format[0] = (char *) malloc(sizeof(char) * (len + 1));
	if (!format[0])
		return (NULL);
	format[0] = ui;
	return (len);
}

size_t	get_print_str(char *str, void **format)
{
	size_t	len;

	len = ft_strlen(str);
	format[0] = (char *) malloc(sizeof(char) * (len + 1));
	if (!format[0])
		return (NULL);
	ft_strfill(str, format, len);
	return (len);
}

size_t	get_print_signedint(ssize_t ui, void **format, char *BASE)
{
	size_t	len;

	len = ft_sintlen(ui, ft_strlen(BASE));
	format[0] = (char *) malloc(sizeof(char) * (len + 1));
	if (!format[0])
		return (NULL);
	ft_sintfill(ui, BASE, format, len);
	return (len);
}

size_t	get_print_unsignedint(size_t ui, void **format, char *BASE)
{
	size_t	len;

	len = ft_uintlen(ui, ft_strlen(BASE));
	format[0] = (char *) malloc(sizeof(char) * (len + 1));
	if (!format[0])
		return (NULL);
	ft_uintfill(ui, BASE, format, len);
	return (len);
}

size_t	get_print_ptr(size_t ui, void **format, char *BASE)
{
	size_t	len;

	len = ft_uintlen(ui, ft_strlen(BASE));
	format[0] = (char *) malloc(sizeof(char) * (len + 1));
	if (!format[0])
		return (NULL);
	ft_ptrfill(ui, BASE, format, len);
	return (len);
}

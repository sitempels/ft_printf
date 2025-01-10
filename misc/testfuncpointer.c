/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testfuncpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:00:25 by stempels          #+#    #+#             */
/*   Updated: 2024/12/12 18:09:03 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	get_print(void *argument, void **format)
{
	char			*res;
	size_t			len;

	len = format[0]->get_len(argument, format);
//	len = get_flag(len, format);
	res = (char *) malloc (sizeof(char) * len + 1);
	if (!res)
		return (NULL);
	res[len] = '\0';
//  fill_flag(len, format, res);
	format[0]->get_fill(argument, format, res, len);
	format[0] = res;
	return (len);
}
 va_list argumeny
 va_arg(va_list)
 va_list

 get_print(info.len)
? argument
 argument = info->va_arg

 info->varg = va_arg(arg, int);

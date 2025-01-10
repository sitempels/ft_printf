/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:34:36 by stempels          #+#    #+#             */
/*   Updated: 2025/01/09 11:58:55 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft.h"

/*----------------------------MACRO-------------------------------------------*/
# define BASE_10 "0123456789"
# define BASE_16 "0123456789abcdef"
# define BASE_X16 "0123456789ABCDEF"

/*----------------------------STRUCTURE---------------------------------------*/
typedef struct s_tprint
{
	char			*base;
	char			type;
	size_t			(*get_len)();
	void			(*get_fill)();
}	t_tprint;

typedef struct s_format
{
	char		*res;
	t_tprint	type;
}	t_format;

/*----------------------------FUNCTION----------------------------------------*/
int			ft_printf(const char *str, ...);
int			str_prs(va_list *arg, char *str, t_format *format, int *printed);
int			is_format(const char *str, t_format *format, ssize_t *i);
void		ft_free(t_format *format);
char		*fill_array(char *dst, char *str, size_t n);
void		fill_char(void *argument, t_format *format, size_t len);
void		fill_str(void **argument, t_format *format, size_t len);
void		fill_sint(void **argument, t_format *format, size_t len);
void		fill_uint(void **argument, t_format *format, size_t len);
size_t		ft_charlen(void);
//size_t		ft_lenstr(char **str);
size_t		ft_sintlen(void *argument, t_format *format);
size_t		ft_uintlen(void *argument, t_format *format);
size_t		get_print(void *argument, t_format *format);
t_tprint	fill_struct(char *base, char type, size_t (*l)(), void (*f)());
t_format	ft_init_type(char type, t_format *format);
//size_t		ft_strlen(char *str);
#endif

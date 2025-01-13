/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stempels <stempels@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 07:34:36 by stempels          #+#    #+#             */
/*   Updated: 2025/01/13 16:04:58 by stempels         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/*----------------------------LIBRARY-----------------------------------------*/
//
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include "libft.h"
//
/*----------------------------MACRO-------------------------------------------*/
//
# define BA_10 "0123456789"
# define BA_16 "0123456789abcdef"
# define BA_X16 "0123456789ABCDEF"
# define FORMAT "csdiuxXp%"
//
/*----------------------------STRUCTURE---------------------------------------*/
/*----------------------------FUNCTION----------------------------------------*/
//
int		ft_printf(const char *str, ...);
int		ft_putnbr_bfd(long long nbr, char *base, int fd);
char	*fill_array(char *dst, char *str, size_t n);
//
//--------------FORMAT_HANDLER
//
int		get_s(char *arg, int fd);
int		get_p(unsigned long long arg, char *base, int fd);
//
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junpkim <junpkim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:54:07 by junpkim           #+#    #+#             */
/*   Updated: 2022/04/08 17:54:08 by junpkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		put_hex_small(unsigned long long n);
int		put_hex_large(unsigned long long n);
char	*split(va_list str);
int		put_point(unsigned int p);
int		ft_printf(const char *s, ...);
int		put_unsignedn(unsigned int n);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:18:06 by mmelo-da          #+#    #+#             */
/*   Updated: 2022/10/25 12:14:14 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdarg.h"

int	ft_printf(const char *msg, ...)
{
	va_list	valist;
	int		len;

	len = 0;
	va_start(valist, msg);
	while (*msg != '\0')
	{
		if (*msg == '%')
		{
			msg++;
			if (*msg == 'c')
				len += ft_print_char((char ) va_arg(valist, int));
			if (*msg == 's')
				len += ft_print_string((char *) va_arg(valist, char *));
			if (*msg == 'p')
				len += ft_print_ptr((uintptr_t) va_arg(valist, uintptr_t));
			if (*msg == 'i' || *msg == 'd')
				len += ft_print_int(va_arg(valist, int));
			if (*msg == 'u')
				len += ft_print_int(va_arg(valist, unsigned int));
			if (*msg == 'x')
				len += ft_print_hex(va_arg(valist, unsigned int), 0);
			if (*msg == 'X')
				len += ft_print_hex(va_arg(valist, unsigned int), 1);
			if (*msg == '%')
				len += ft_print_char('%');
			msg++;
		}
		else
		{
			len += ft_print_char(*msg);
			msg++;
		}
	}
	va_end(valist);
	return (len);
}

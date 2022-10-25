/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:18:06 by mmelo-da          #+#    #+#             */
/*   Updated: 2022/10/25 12:36:49 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdarg.h"


int	ft_formats(char *format, va_list valist)
{
	if (*format == 'c')
		return (ft_print_char((char ) va_arg(valist, int)));
	if (*format == 's')
		return (ft_print_string((char *) va_arg(valist, char *)));
	if (*format == 'p')
		return (ft_print_ptr((uintptr_t) va_arg(valist, uintptr_t)));
	if (*format == 'i' || *format == 'd')
		return (ft_print_int(va_arg(valist, int)));
	if (*format == 'u')
		return (ft_print_int(va_arg(valist, unsigned int)));
	if (*format == 'x')
		return (ft_print_hex(va_arg(valist, unsigned int), 0));
	if (*format == 'X')
		return (ft_print_hex(va_arg(valist, unsigned int), 1));
	if (*format == '%')
		return (ft_print_char('%'));
	return (0);
}

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
			len += ft_formats((char *)msg, valist);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 12:40:09 by mmelo-da          #+#    #+#             */
/*   Updated: 2022/10/25 12:40:12 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdint.h"
#include "unistd.h"

int	ft_print_hex(long int num, int upper_flag)
{
	return (ft_put_hex(num, upper_flag));
}

int	ft_print_char(char c)
{
	return (ft_put_char(c));
}

int	ft_print_string(char *s)
{
	int		s_len;

	if (s == NULL)
		return (ft_print_string("(null)"));
	s_len = 0;
	while (*s != '\0')
	{
		ft_print_char(*s);
		s_len++;
		s++;
	}
	return (s_len);
}

int	ft_print_ptr(uintptr_t ptr)
{
	if (ptr == (uintptr_t) NULL)
		return (ft_print_string("(nil)"));
	return (ft_print_string("0x") + ft_put_hex(ptr, 0));
}

int	ft_print_int(long int num)
{
	char	*hex_map;

	hex_map = "0123456789";
	if (num < 0)
		return (ft_print_char('-') + ft_print_int(-1 * num));
	if (num < 10 && num >= 0)
		return (ft_print_char(hex_map[num]));
	else
		return (ft_print_int(num / 10) + ft_print_char(hex_map[num % 10]));
}

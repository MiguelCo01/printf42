/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmelo-da <mmelo-da@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 11:18:21 by mmelo-da          #+#    #+#             */
/*   Updated: 2022/10/25 12:06:02 by mmelo-da         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "stdint.h"

int	ft_printf(const char	*msg, ...);


int	ft_put_char(char c);
int	ft_put_hex(uintptr_t ptr, int u_flag);

int	ft_print_hex(long int num, int upper_flag);
int	ft_print_char(char c);
int	ft_print_string(char *s);
int	ft_print_ptr(uintptr_t ptr);
int	ft_print_int(long int num);

#endif

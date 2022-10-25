#include "stdint.h"
#include "unistd.h"

int	ft_put_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_put_hex(uintptr_t ptr, int u_flag)
{
	char	*hex_map;

	hex_map = "0123456789abcdef";
	if (u_flag == 1)
		hex_map = "0123456789ABCDEF";
	if (ptr < 16 )
		return (ft_put_char(hex_map[ptr]));
	else
		return (ft_put_hex(ptr / 16, u_flag) + ft_put_char(hex_map[ptr % 16]));
}

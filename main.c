#include "ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	unsigned int i;

	(void)ac;
	i = 9876;
	ft_printf("%s\nft_printf = %#065x\n", av[1], i);
	return (0);
}

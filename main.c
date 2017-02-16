#include "include/ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	unsigned long long int i;
	int ret;

	(void)ac;
	(void)av;
	i = 4294967296;
	ret = ft_printf("%llx\n", i);
	ft_printf("%d\n", ret);
	return (0);
}

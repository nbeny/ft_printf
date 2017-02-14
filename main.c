#include "include/ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int i;
	int ret;

	(void)ac;
	i = ft_atoi(av[2]);
	ret = ft_printf("%+10s : %40d\n", av[1], i);
	ft_printf("%+i\n", ret);
	return (0);
}

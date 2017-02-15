#include "include/ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int i;
	int ret;

	(void)ac;
	(void)av;
	i = 100;
	ret = ft_printf("[%-50x]\n", i);
	ft_printf("%d", ret);
	return (0);
}

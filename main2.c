#include "include/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

int		main(int ac, char **av)
{
	int	ret;

	(void)ac;
	(void)av;
	ret = ft_printf("%%500%% : [%500%]\n");
	ret = ft_printf("%%10.5d : [%10.5d]\n", 3543);
	ret = ft_printf("%%*5x : [%*5x]\n", 10, 6546);
	ret = ft_printf("%%6.8o : [%6.8o]\n", 6546);
	ret = ft_printf("%%*.*s : [%*.*s]\n", 20, 10, "qwertqwertasdfg");
	ret = ft_printf("%%.4s : [%.4s]\n", "Bonjour !");
	ret = ft_printf("%%06u : %06u\n", 6546);
	ret = ft_printf("%%06x : %06x\n", 6546);
	ret = ft_printf("%%06v : %06v\n", 6546);
	return (0);
}

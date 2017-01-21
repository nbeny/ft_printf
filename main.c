#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	int	i = 96;
	char	str[5] = "tot\n";

	printf("%D\n", i);
	printf("%\n", str);
	ft_putstr(str);
	return (0);
}

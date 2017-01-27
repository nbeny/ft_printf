#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	long int c;

	c = -152;
	printf("%    LU\n", c);
	return (0);
}

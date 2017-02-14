#include "libft.h"

void	ft_putcstr(char c, int size)
{
	int i;

	i = 0;
	if (ft_isprint((int)c))
	{
		while (i < size)
		{
			ft_putchar(c);
			i++;
		}
	}
}

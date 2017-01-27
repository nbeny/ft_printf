#include "libft.h"

void	ft_putstr_printf(const char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '%')
	{
		ft_putchar(s[i]);
		i++;
	}
}

#include "ft_printf.h"

int	ft_count(char *format)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
				i++;
			count++;
		}
		i++;
	}
	return (count);
}

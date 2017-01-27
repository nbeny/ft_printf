#include "ft_printf.h"

int		ft_gestion_zero(const char *format, int i)
{
	int zero;

	while (format[i] == '0')
		i++;
	zero = ft_atoi(format[i]);
	return (zero);
}

int		ft_gestion_plus(const char *format, int i)
{
	int space;

	while (format[i] == '+')
		i++;
	space = ft_atoi(format[i]);
	return (space);
}

int		ft_gestion_moins(const char *format, int i)
{
	int space;

	while (format[i] == '-')
		i++;
	space = ft_atoi(format[i]);
	return (space);
}

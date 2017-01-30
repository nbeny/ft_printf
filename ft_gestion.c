#include "ft_printf.h"

int		ft_gestion_zero(const char *format, int i)
{
	int zero;

	while (format[i] == '0' || format[i] == '+')
		i++;
	zero = ft_atoi(format[i]);
	return (zero);
}

int		ft_gestion_plus(const char *format, int i)
{
	int s_plus;

	while (format[i] == '+')
		i++;
	if (format[i] != '-')
		s_plus = ft_atoi(format[i]);
	else
		s_plus = 1;
	return (s_plus);
}

int		ft_gestion_moins(const char *format, int i)
{
	int s_moins;

	while (format[i] == '-' || format[i] == '+')
		i++;
	s_moins = ft_atoi(format[i]);
	return (s_moins);
}

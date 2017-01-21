#include "ft_printf.h"

int	      ft_hh(char **str, char ***format, va_list argptr)
{
	int     ret;

	ret = 1;
	if (**format[3] == 'd' || **format[3] == 'D' ||
	    **format[3] == 'i' || **format[3] == 'I')
		ret += ft_hhd(str, format, argptr);
	else if (**format[3] == 'o' || **format[3] == 'O' ||
		 **format[3] == 'u' || **format[3] == 'U' ||
		 **format[3] == 'x' || **format[3] == 'X')
		ret += ft_hho(str, format, argptr);
	else if (**format[3] == 'n' || **format[3] == 'N')
		ret += ft_hhn(str, format, argptr);
	else
		return (-3);
	return (ret);
}

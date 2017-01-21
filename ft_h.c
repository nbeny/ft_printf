#include "ft_printf.h"

static int	ft_hd(char **str, char ***format, va_list argptr);
{
	
}

int		ft_h(char **str, char ***format, va_list argptr)
{
	int	ret;

	ret = 1;
	if (**format[2] == 'h' || **format[2] == 'H')
		ret += ft_hh(str, argptr);
	else if (**format[2] == 'd' || **format[2] == 'D' ||
		 **format[2] == 'i' || **format[2] == 'I')
		ret += ft_hd(str, format,argptr);
	else if (**format[2] == 'o' || **format[2] == 'O' ||
		 **format[2] == 'u' || **format[2] == 'U' ||
		 **format[2] == 'x' || **format[2] == 'X')
		ret += ft_ho(str, format, argptr);
	else if (**format[2] == 'n' || **format[2] == 'N')
		ret += ft_hn(str, format, argptr);
	else
		return (-2);
	return (ret);
}

#include "ft_printf.h"

static int      ft_ll(char **str, char **fomat,  va_list argptr, int i)
{
	int     ret;

	ret = 1;
	if (*format[3] == 'd' || *format[3] == 'D' ||
		*format[3] == 'i' || *format[3] == 'I')
		ret += ft_lld(str, argptr, i);
	else if (*format[3] == 'o' || *format[3] == 'O' ||
			 *format[3] == 'u' || *format[3] == 'U' ||
			 *format[3] == 'x' || *format[3] == 'X')
		ret += ft_llo(str, argptr, i);
	else if (*format[3] == 'n' || *format[3] == 'N')
		ret += ft_lln(str, argptr, i);
	else
		return (-3);
	return (ret);
}

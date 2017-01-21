#include "ft_printf.h"

static int      ft_ll(char **str, va_list argptr)
{
	int     ret;

	ret = 1;
	if (*str[3] == 'd' || *str[3] == 'D' || *str[3] == 'i' || *str[3] == 'I')
		ret += ft_lld(str, argptr);
	else if (*str[3] == 'o' || *str[3] == 'O' || *str[3] == 'u' || *str[3] == 'U' ||
		 *str[3] == 'x' || *str[3] == 'X')
		ret += ft_llo(str, argptr);
	else if (*str[3] == 'n' || *str[3] == 'N')
		ret += ft_lln(str, argptr);
	else
		return (-3);
	return (ret);
}

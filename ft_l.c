#include "ft_printf.h"

int	ft_l(char **str, va_list argptr)
{
	int	ret;

	ret = 1;
	if (*str[2] == 'l' || *str[2] == 'L')
		ret += ft_ll(str, argptr);
	else if (*str[2] == 'd' || *str[2] == 'D' || *str[2] == 'i' || *str[2] == 'I')
		ret += ft_ld(str, argptr);
	else if (*str[2] == 'o' || *str[2] == 'O' || *str[2] == 'u' || *str[2] == 'U' ||
		 *str[2] == 'x' || *str[2] == 'X')
		ret += ft_lo(str, argptr);
	else if (*str[2] == 'n' || *str[2] == 'N')
		ret += ft_ln(str, argptr);
	else
		return (-2);
	return (ret);
}

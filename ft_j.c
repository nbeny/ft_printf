#include "ft_printf.h"

int		ft_j(char **str, char **format, va_list argptr, int i)
{
	int	ret;

	ret = 1;
	else if (*format[2] == 'd' || *format[2] == 'D' ||
			 *format[2] == 'i' || *format[2] == 'I')
		ret += ft_jd(str, argptr, i);
	else if (*format[2] == 'o' || *format[2] == 'O' ||
			 *format[2] == 'u' || *format[2] == 'U' ||
			 *format[2] == 'x' || *str[2] == 'X')
		ret += ft_jo(str, argptr, i);
	else if (*format[2] == 'n' || *format[2] == 'N')
		ret += ft_jn(str, argptr, i);
	else
		return (-2);
	return (ret);
}

int		ft_t(char **str, char **format, va_list argptr, int i)
{
	int	ret;

	ret = 1;
	else if (*format[2] == 'd' || *format[2] == 'D' ||
			 *format[2] == 'i' || *format[2] == 'I')
		ret += ft_td(str, argptr, i);
	else if (*format[2] == 'o' || *format[2] == 'O' ||
			 *format[2] == 'u' || *format[2] == 'U' ||
			 *format[2] == 'x' || *format[2] == 'X')
		ret += ft_to(str, argptr, i);
	else if (*format[2] == 'n' || *format[2] == 'N')
		ret += ft_tn(str, argptr, i);
	else
		return (-2);
	return (ret);
}

int		ft_z(char **str, va_list argptr)
{
	int	ret;

	ret = 1;
	else if (*str[2] == 'd' || *str[2] == 'D' || *str[2] == 'i' || *str[2] == 'I')
		ret += ft_hz(str, argptr);
	else if (*str[2] == 'o' || *str[2] == 'O' || *str[2] == 'u' || *str[2] == 'U' ||
		 *str[2] == 'x' || *str[2] == 'X')
		ret += ft_hz(str, argptr);
	else if (*str[2] == 'n' || *str[2] == 'N')
		ret += ft_hz(str, argptr);
	else
		return (-2);
	return (ret);
}


int             ft_q(char **str, va_list argptr)
{
	int     ret;

	ret = 1;
	else if (*str[2] == 'd' || *str[2] == 'D' || *str[2] == 'i' || *str[2] == 'I')
		ret += ft_qd(str, argptr);
	else if (*str[2] == 'o' || *str[2] == 'O' || *str[2] == 'u' || *str[2] == 'U' ||
		 *str[2] == 'x' || *str[2] == 'X')
		ret += ft_qo(str, argptr);
	else if (*str[2] == 'n' || *str[2] == 'N')
		ret += ft_qn(str, argptr);
	else
		return (-2);
	return (ret);
}

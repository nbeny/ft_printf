#include "ft_printf.h"

static void	ft_hd(char **str, va_list argptr, int i);
{
	short c;
	char *tmp;

	c = va_arg(argptr, short);
	tmp = ft_itoa((int)c);
	*str = ft_strjoin(*str, tmp);
	free(tmp);
	tmp == NULL;
}

static void	ft_ho(char **str, va_list argptr, int i)
{
	unsigned short c;
	char *tmp;

	c = va_arg(argptr, unsigned short);
	tmp = ft_itoa((int)c);
	*str = ft_strjoint(*str, tmp);
	free(tmp);
}
/*
static void	ft_hn(char **str, va_list argptr, int i)
{
	short *c;
	char *tmp;

	c = va_arg(argptr, short *);
	tmp =
}
*/
int			ft_h(char **str, char **format, va_list argptr, int i)
{
	int	ret;

	ret = 1;
	if (*format[2] == 'h' || *format[2] == 'H')
		ret += ft_hh(str, argptr, i);
	else if (*format[2] == 'd' || *format[2] == 'D' ||
		 *format[2] == 'i' || *format[2] == 'I')
		ret += ft_hd(str, argptr, i);
	else if (*format[2] == 'o' || *format[2] == 'O' ||
			 *format[2] == 'u' || *format[2] == 'U' ||
			 *format[2] == 'x' || *format[2] == 'X')
		ret += ft_ho(str, argptr, i);
	else if (*format[2] == 'n' || *format[2] == 'N')
		ret += ft_hn(str, argptr, i);
	else
		return (-2);
	return (ret);
}

#include "../include/ft_printf.h"

int	ft_handler_wc(t_flag *f, va_list *ap)
{
	wchar_t wc;
	wchar_t ws[2];

	wc = va_arg(*ap, wchar_t);
	ws[0] = wc;
	ws[1] = 0;
	if (ws[0] < 0 && ws[0] > 55295 && ws[0] < 57344 && ws[0] > 1114111)
	{
		f->ret = -1;
		return (-1);
	}
	f->ret += 1;
	f->warg = ws;
	f->size = 1;
	if (f->flag[1] > 1)
		return (ft_flags_char(f));
	f->ret += ft_strlen(f->arg);
	ft_putstr(f->arg);
	return (0);
}

int	ft_handler_c(t_flag *f, va_list *ap)
{
	char c;
	char s[2];

	if (f->flag[10] == 1)
	{
		ft_handler_wc(f, ap);
		return (0);
	}
	f->ret += 1;
	c = (char)va_arg(*ap, int);
	s[0] = c;
	s[1] = 0;
	f->arg = s;
	f->size = 1;
	if (f->flag[1] > 1)
		return (ft_flags_char(f));
	f->ret += ft_strlen(f->arg);
	ft_putstr(f->arg);
	return (0);
}

#include "../include/ft_printf.h"

int	ft_handler_p(t_flag *f, va_list *ap)
{
	f->arg = ft_ulitoa_base((unsigned long long int)va_arg(*ap, unsigned long long int), 16);
	if (f->flag[1] > ft_strlen(f->arg))
		return (ft_flags_int(f));
	ft_putstr(f->arg);
	f->ret += ft_strlen(f->arg);
	return (0);
}

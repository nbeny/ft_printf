#include "ft_printf.h"

int		ft_modifier_d(t_flag *f, va_list *ap)
{
	if (flag[7] == 1)
		return (0);
	return (0);
}

int		ft_handler_d(t_flag *f, va_list *ap)
{
	if (flag[7] == 1 || flag[8] == 1 ||
	    flag[9] == 1 || flag[10] == 1 ||
	    flag[11] == 1 || flag[12] == 1)
		return (ft_modifier_d(f, ap));
	f->arg = ft_itoa((int)va_arg(ap, int));
	if (flag[1] > ft_strlen(f->arg))
		ft_flags_int(f);
	ft_putstr(f->arg);
	return (0);
}

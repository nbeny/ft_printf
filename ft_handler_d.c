#include "ft_printf.h"

int		ft_modifier_d(t_flag *f, va_list *ap)
{
	if (flag[7] == 1)
		return (ft_handler_hhd(f, ap));
	if (flag[8] == 1)
		return (ft_handler_hd(f, ap));
	if (flag[9] == 1)
		return (ft_handler_lld(f, ap));
	if (flag[10] == 1)
		return (ft_handler_ld(f, ap));
	if (flag[11] == 1)
		return (ft_handler_zd(f, ap));
	if (flag[12] == 1)
		return (ft_handler_td(f, ap));
	return (0);
}

int		ft_handler_wd(t_flag *f, va_list *ap)
{
	f->arg = ft_litoa((long long int)va_arg(ap, long int));
	if (flag[1] > ft_strlen(f->arg))
		ft_flags_int(f);
	ft_putstr(f->arg);
	return (0);
}

int		ft_handler_d(t_flag *f, va_list *ap)
{
	if (flag[7] == 1 || flag[8] == 1 ||
	    flag[9] == 1 || flag[10] == 1 ||
	    flag[11] == 1 || flag[12] == 1)
		ft_modifier_d(f, ap);
	if (flag[7] != 1 && flag[8] != 1 &&
		flag[9] != 1 && flag[10] != 1 &&
		flag[11] != 1 && flag[12] != 1)
		f->arg = ft_itoa((int)va_arg(ap, int));
	if (flag[1] > ft_strlen(f->arg))
		ft_flags_int(f);
	ft_putstr(f->arg);
	return (0);
}

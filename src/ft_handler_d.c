#include "../include/ft_printf.h"

int		ft_modifier_d(t_flag *f, va_list *ap)
{
	if (f->flag[7] == 1)
		return (ft_handler_hhd(f, ap));
	if (f->flag[8] == 1)
		return (ft_handler_hd(f, ap));
	if (f->flag[9] == 1)
		return (ft_handler_lld(f, ap));
	if (f->flag[10] == 1)
		return (ft_handler_ld(f, ap));
	if (f->flag[11] == 1)
		return (ft_handler_jd(f, ap));
	if (f->flag[12] == 1)
		return (ft_handler_zd(f, ap));
	return (0);
}

int		ft_handler_wd(t_flag *f, va_list *ap)
{
	f->arg = ft_litoa_base((long int)va_arg(*ap, long int), 10);
	if (f->flag[1] > ft_strlen(f->arg))
		return(ft_flags_int(f));
	f->ret += ft_strlen(f->arg);
	ft_putstr(f->arg);
	return (0);
}

int		ft_handler_d(t_flag *f, va_list *ap)
{
	if (f->flag[7] == 1 || f->flag[8] == 1 ||
	    f->flag[9] == 1 || f->flag[10] == 1 ||
	    f->flag[11] == 1 || f->flag[12] == 1)
		return (ft_modifier_d(f, ap));
	if (f->flag[7] != 1 && f->flag[8] != 1 &&
		f->flag[9] != 1 && f->flag[10] != 1 &&
		f->flag[11] != 1 && f->flag[12] != 1)
		f->arg = ft_itoa((int)va_arg(*ap, int));
	if (f->flag[1] > ft_strlen(f->arg))
		return (ft_flags_int(f));
	f->ret += ft_strlen(f->arg);
	ft_putstr(f->arg);
	return (0);
}

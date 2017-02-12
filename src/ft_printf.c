#include "../include/ft_printf.h"

static t_flag	*ft_init_f(t_flag *f)
{
	int i;

	i = -1;
	f->ret = 0;
	f->i = 0;
	f->c = 0;
	f->arg = NULL;
	f->warg = NULL;
	f->sign = 0;
	while (++i < 13)
		f->flag[i] = 0;
	f->size = 0;
	f->size = 0;
	f->Ox = NULL;
	f->s = NULL;
	return (f);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flag	*f;
	int	i;

	va_start(ap, format);
	i = -1;
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			f = ft_init_f(f);
			f->format = (char *)&format[++i];
			if (ft_dispatcher(f, &ap) == -1)
				break;
			i += f->i;
		}
		else if (format[i] != '\0' && format[i] != '%')
			ft_putchar(format[i]);
	}
	va_end(ap);
	return (f->ret);
}

#include "../include/ft_printf.h"

void		ft_free(t_flag *f)
{
	if (f->flag[0] >= 0 && f->arg != NULL &&
	    f->arg[0] != '\0' && f->arg[0] != '0')
	{
		if (f->c == 's' || f->c == 'S' || f->c == 'p' ||
		    f->c == 'd' || f->c == 'D' || f->c == 'i' ||
		    f->c == 'o' || f->c == 'O' || f->c == 'u' ||
		    f->c == 'U' || f->c == 'x' || f->c == 'X' ||
		    f->c == 'c' || f->c == 'C')
			free(f->arg);
	}
}

static int	ft_init_f(t_flag *f)
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
	return (f);
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flag	f;
	int	i;

	va_start(ap, format);
	i = -1;
	ft_bzero(buf, 4096);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			f = ft_init_flags(f);
			f.format = (char *)&format[++i];
			if (ft_dispatcher(&f, &ap) == -1)
				break;
			i += f.i;
		}
		else if (format[i] != '\0' && format[i] != '%')
			ft_putchar(format[i]);
	}
	if (g_i > 0)
		ft_display(&f);
	va_end(ap);
	return (f.ret);
}

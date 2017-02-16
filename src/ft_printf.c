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
	f->Ox = NULL;
	return (f);
}

int			ft_printf(const char *format, ...)
{
	va_list	ap;
	t_flag	*f;
	int	i;
	int	ret;

	va_start(ap, format);
	i = -1;
	ret = 0;
	f = (t_flag *)malloc(sizeof(t_flag));
	if (f == NULL)
		return (0);
	while (format[++i] != '\0')
	{
		if (format[i] == '%')
		{
			f = ft_init_f(f);
			f->format = (char *)&format[++i];
			ft_dispatcher(f, &ap);
			ret += f->ret;
			i += f->i;
		}
		else
		{
			ft_putchar(format[i]);
			ret++;
		}
	}
	va_end(ap);
	free(f);
	return (ret);
}

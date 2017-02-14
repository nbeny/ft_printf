#include "../include/ft_printf.h"

int	ft_handler(t_flag *f)
{
	char s[2];

	s[0] = '%';
	s[1] = 0;
	f->arg = s;
	if (f->flag[1] > 1)
		return (ft_flags_char(f));
	f->ret = 1;
	ft_putstr(f->arg);
	free(f->arg);
	return (0);
}

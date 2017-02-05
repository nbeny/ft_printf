#include "ft_printf.h"

static int	ft_flag_moins(t_flag *f)
{
	char	*s;
	int	i;

	i = f->flag[1] - f->size;
	s = ft_bchar(' ', i);
	if (arg != NULL)
		ft_putstr(arg);
	else if (warg != NULL)
		ft_putstr(warg);
	ft_putstr(s);
	free(s);
	s = NULL;
	return (0);
}

static int	ft_flag_plus(t_flag *f)
{
	char	*s;
	int	i;

	i = f->flag[1] - f->size;
	s = ft_bchar(' ', i);
	ft_putstr(s);
	if (arg != NULL)
		ft_putstr(arg);
	else if (warg != NULL)
		ft_putstr(warg);
	free(s);
	s = NULL;
	return (0);
}

static int	ft_flag_zero(t_flag *f)
{
	char	*s;
	int	i;

	i = f->flag[1] - f->size;
	s = ft_bchar('0', i);
	ft_putstr(s);
	if (arg != NULL)
		ft_putstr(arg);
	if (warg != NULL)
		ft_putstr(warg);
	free(s);
	s = NULL;
	return (0);
}

int		ft_flags_char(t_flag *f)
{
	if (flag[4] == 1)
		ft_flag_moins(f);
	else if (flags[3] == 1)
		ft_flag_zero(f);
	else if (flags[5] == 1 || flags[6] == 1 || flags[1] > 1)
		ft_flag_plus(f);
	return (0);
}

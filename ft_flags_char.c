#include "ft_printf.h"

static int	ft_flag_moins(t_flag *f)
{
	int	i;

	i = f->flag[1] - f->size;
	f->s = ft_bchar(' ', i);
	if (f->arg != NULL)
		ft_putstr(f->arg);
	else if (f->warg != NULL)
		ft_putstr(f->warg);
	ft_putstr(f->s);
	free(f->s);
	f->s = NULL;
	return (0);
}

static int	ft_flag_plus(t_flag *f)
{
	char	*s;
	int	i;

	i = f->flag[1] - f->size;
	f->s = ft_bchar(' ', i);
	ft_putstr(f->s);
	if (f->arg != NULL)
		ft_putstr(f->arg);
	else if (f->warg != NULL)
		ft_putstr(f->warg);
	free(f->s);
	f->s = NULL;
	return (0);
}

static int	ft_flag_zero(t_flag *f)
{
	char	*s;
	int	i;

	i = f->flag[1] - f->size;
	f->s = ft_bchar('0', i);
	ft_putstr(f->s);
	if (f->arg != NULL)
		ft_putstr(f->arg);
	if (f->warg != NULL)
		ft_putstr(f->warg);
	free(f->s);
	f->s = NULL;
	return (0);
}

int		ft_flags_char(t_flag *f)
{
	if (f->flag[4] == 1)
		return (ft_flag_moins(f));
	if (f->flags[3] == 1)
		return (ft_flag_zero(f));
	if (f->flags[5] == 1 || f->flags[6] == 1 || f->flags[1] > 1)
		return (ft_flag_plus(f));
	if (f->arg != NULL)
		ft_putstr(f->arg);
	if (f->warg != NULL)
		ft_putstr(f->warg);
	return (0);
}

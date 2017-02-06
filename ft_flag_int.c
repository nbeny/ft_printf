#include "ft_printf.h"

int	ft_flag_Ox(t_flag *f)
{
	if (!(f->Ox = (char *)malloc(sizeof(char) * 3)))
		f->Ox = NULL;
	ft_bzero(f->Ox, 3);
	if (f->c == 'o' || f->c == 'O' ||
	    f->c == 'x' || f->c == 'X')
	{
		f->Ox[0] = '0';
		return (1);
	}
	if (f->c == 'x')
	{
		f->Ox[1] = 'x';
		return (2);
	}
	if (f->c == 'X')
	{
		f->Ox[1] = 'X';
		f->arg = ft_capitalizer(f->arg);
		return (2);
	}
	return (0);
}

int	ft_flag_zero(t_flag *f)
{
	int i;

	i = f->flag[1] - f->size;
	if (f->flag[2] == 1)
		i = i - ft_flag_Ox(f);
	if (i < 0)
		i = 0;
	f->s = ft_bchar('0', i);
	if ((f->c == 'd' || f->c == 'D' ||
	     f->c == 'x') && flag[5] == 1)
		if (f->sign == '+')
			f->s[0] = '+';
	if (sign == '-')
	{
		f->arg = ft_rotcstring(f->arg);
		f->s[0] = '-';
	}
	if (f->flag[2] == 1)
	{
		ft_putstr(f->Ox);
		free(f->Ox);
	}
	ft_putstr(f->s);
	free(f->s);
	return (0);
}

int	ft_flag_moins(t_flag *f)
{
	int i;

	i = f->flag[1] - f->size;
	if (f->flag[2] == 1)
		i = i - ft_flag_Ox(f);
	if (i < 0)
		i = 0;
	f->s = ft_bchar(' ', i);
	if ((f->c == 'd' || f->c == 'D' ||
	     f->c == 'i') && flag[5] == 1)
		if (f->sign == '+')
			f->s[i] = '+';
	ft_putstr(f->s);
	free(f->s);
	f->s = NULL;
	if (f->flag[2] == 1)
	{
		ft_putstr(f->Ox);
		free(f->Ox);
		f->Ox = NULL;
	}
	return (0);
}

int	ft_flags_plus(t_flag *f)
{
	int i;

	i = f->flag[1] - f->size;
	if (f->flag[2] == 1)
		i = i - ft_flag_Ox(f);
	if (i < 0)
		i = 0;
	f->s = ft_bchar(' ', i);
	if ((f->c == 'd' || f->c == 'D' ||
	     f->c == 'i') && f->flag[5] == 1)
		if (f->sign == '+')
			f->s[i] = '+';
	ft_putstr(f->s);
	free(f->s);
	f->s = NULL;
	if (f->flag[2] == 1)
	{
		ft_putstr(f->Ox);
		free(f->Ox);
		f->Ox = NULL;
	}
	return (0);
}

int	ft_flags_int(t_flag *f)
{
	if (flag[5] == 1)
		f->sign = ft_sign(f->arg);
	if (flag[1] > ft_strlen(f->arg))
	{
		if (flag[3] == 1)
			return (ft_flag_zero(f));
		else if (flag[4] == 1)
			return (ft_flag_moins(f));
		else if (flag[5] == 1 || flag[6] == 1 ||
			 flag[1] > ft_strlen(f->arg))
			return (ft_flag_plus(f));
	}
	ft_putstr(f->arg);
	return (0);
}

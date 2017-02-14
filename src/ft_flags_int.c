#include "../include/ft_printf.h"

static int	ft_flag_Ox(t_flag *f)
{
	int i;

	i = 0;
	if (!(f->Ox = (char *)malloc(sizeof(char) * 3)))
		f->Ox = NULL;
	ft_bzero(f->Ox, 3);
	if (f->c == 'o' || f->c == 'O' ||
	    f->c == 'x' || f->c == 'X')
	{
		f->Ox[0] = '0';
		i++;
	}
	if (f->c == 'x')
	{
		f->Ox[1] = 'x';
		i++;
	}
	if (f->c == 'X')
	{
		f->Ox[1] = 'X';
		f->arg = ft_capitalizer(f->arg);
		i++;
	}
	return (i);
}

static int	ft_flag_zero(t_flag *f)
{
	int i;

	i = f->flag[1] - f->size;
	if (f->flag[2] == 1)
		i = i - ft_flag_Ox(f);
	if (i < 0)
		i = 0;
	f->s = ft_bchar('0', i);
	if ((f->c == 'd' || f->c == 'D' ||
	     f->c == 'x') && f->flag[5] == 1)
		if (f->sign == '+')
			f->s[0] = '+';
	if (f->sign == '-')
	{
		f->arg = ft_rotcstring(f->arg);
		f->s[0] = '-';
	}
	if (f->flag[2] == 1)
	{
		f->ret += ft_strlen(f->Ox);
		ft_putstr(f->Ox);
		free(f->Ox);
	}
	f->ret += ft_strlen(f->s);
	ft_putstr(f->s);
	free(f->s);
	f->ret += ft_strlen(f->arg);
	ft_putstr(f->arg);
	free(f->arg);
	return (0);
}

static int	ft_flag_moins(t_flag *f)
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
	if (f->flag[2] == 1)
	{
		f->ret += ft_strlen(f->Ox);
		ft_putstr(f->Ox);
		free(f->Ox);
		f->Ox = NULL;
	}
	f->ret += ft_strlen(f->arg);
	ft_putstr(f->arg);
	free(f->arg);
	f->ret += ft_strlen(f->s);
	ft_putstr(f->s);
	free(f->s);
	return (0);
}

static int	ft_flag_plus(t_flag *f)
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
	f->ret += ft_strlen(f->s);
	ft_putstr(f->s);
	free(f->s);
	f->s = NULL;
	if (f->flag[2] == 1)
	{
		f->ret += ft_strlen(f->Ox);
		ft_putstr(f->Ox);
		free(f->Ox);
		f->Ox = NULL;
	}
	f->ret += ft_strlen(f->arg);
	ft_putstr(f->arg);
	free(f->arg);
	return (0);
}

int	ft_flags_int(t_flag *f)
{
	f->size = ft_strlen(f->arg);
	if (f->flag[5] == 1)
		f->sign = ft_sign(f->arg);
	if (f->flag[1] > ft_strlen(f->arg))
	{
		if (f->flag[3] == 1)
			return (ft_flag_zero(f));
		else if (f->flag[4] == 1)
			return (ft_flag_moins(f));
		else if (f->flag[5] == 1 || f->flag[6] == 1 ||
			 f->flag[1] > ft_strlen(f->arg))
			return (ft_flag_plus(f));
	}
	f->ret += ft_strlen(f->arg);
	ft_putstr(f->arg);
	return (0);
}

static char	*ft_zero(int i)
{
	int	j;
	char	*s;

	j = 0;
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		s[j] = '0';
		j++;
	}
	s[j] = 0;
	return (s);
}

void		ft_int(const char *format, va_list arg, int i, t_var *g)
{
	int	nb;
	char	*s;
	char	*zero;
	char	*strjoin;

	nb = va_arg(arg, int);
	if (zero != 0)
	{
		s = ft_itoa(nb);
		if (nb >= 0 && g->zero > ft_strlen(s))
		{
			zero = ft_zero(g->zero - ft_strlen(s));
			if (g->s_plus != 0)
				zero[0] = '+';
			strjoin = ft_strjoin(zero, s);
			free(s);
			free(zero);
			s = NULL;
			zero = NULL;
		}
		if (nb < 0 && g->zero > ft_strlen(s))
		{
			zero = ft_zero(g->zero - ft_strlen(s));
			
		}
	}
	else
	{
		if (g->s_plus == 1)
		{
			if (nb >= 0)
				ft_putchar('+');
			ft_putnbr(nb);
		}
	}
}

#include <stdlib.h>

static void	ft_init(char *s)
{
	s[0] = '0';
	s[1] = '1';
	s[2] = '2';
	s[3] = '3';
	s[4] = '4';
	s[5] = '5';
	s[6] = '6';
	s[7] = '7';
	s[8] = '8';
	s[9] = '9';
	s[10] = 'a';
	s[11] = 'b';
	s[12] = 'c';
	s[13] = 'd';
	s[14] = 'e';
	s[15] = 'f';
}

static int	ft_size_nbr(int *tab, char *s, intmax_t nb, int base)
{
	int i;

	i = 0;
	if (nb < 0)
		nb = nb * -1;
	while (nb != 0)
	{
		tab[i] = s[nb % base];
		nb = nb / base;
		i++;
	}
	i--;
	return (i);

}

char		*ft_max_itoa_base(intmax_t nb, int base)
{
	char		*itoa;
	char		s[16];
	int		tab[64];
	int		i;
	int		j;
	intmax_t	n;

	n = nb;
	ft_init(s);
	i = ft_size_nbr(tab, s, nb, base);
	itoa = (char *)malloc(sizeof(char) * (i + 1));
	j = 0;
	if (n < 0)
	{
		itoa[0] = '-';
		n = 1;
		j++;
	}
	while (i >= 0)
	{
		itoa[j] = tab[i];
		j++;
		i--;
	}
	itoa[j] = 0;
	return (itoa);
}

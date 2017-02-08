#include "libft.h"

static char		*ft_reverse_itoa(char *itoa)
{
	size_t	i;
	size_t	j;
	char	tmp;

	i = 0;
	j = 0;
	while (itoa[j])
		j++;
	j--;
	while (i < j)
	{
		tmp = itoa[i];
		itoa[i] = itoa[j];
		itoa[j] = tmp;
		i++;
		j--;
	}
	return (itoa);
}

static size_t	ft_ccl_malloc(uintmax_t n)
{
	size_t	i;

	i = 0;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char			*ft_umax_itoa(uintmax_t n)
{
	char	*itoa;
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_ccl_malloc(n);
	if (!(itoa = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	while (n > 9)
	{
		itoa[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (n <= 9)
		itoa[i++] = n % 10 + '0';
	itoa[i] = '\0';
	itoa = ft_reverse_itoa(itoa);
	return (itoa);
}

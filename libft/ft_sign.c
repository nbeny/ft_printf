#include "libft.h"

char	ft_sign(char *s)
{
	if (s[0] == '-')
		return ('-');
	else
		return ('+');
}
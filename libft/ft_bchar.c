#include "libft.h"

char	*ft_bchar(char c, int size)
{
	int i;
	char *s;

	i = 0;
	if (!(s = (char *)malloc(sizeof(char) * (size + 1))))
		s = NULL;
	while (s[i] && i <= size)
	{
		s[i] = c;
		i++;
	}
	s[i] = 0;
	return (s);
}

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_num
{
	int	d;
	long	ld;
	short	hd;
	float	f;
	double	lf;
}		t_num;
typedef struct	s_str
{
	char	c;
	char	*s;
	void	*p;
	
}		t_str;

int	ft_printf(const char *str, ...);
#endif

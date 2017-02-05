#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>

char		g_buf[4096];
int		g_i;

typedef struct	s_flag
{
	int	ret;
	char	*format;
	int	i;
	char	c;
	char	*arg;
	wchar_t	*warg;
	char	sign;
	va_list	ap;
	int	flag[13];
}		t_flag;

typedef struct	s_spec
{
	int	(*ptr)();
	char	c;
}		t_spec;

int		ft_printf(const char *format, ...);
void		ft_free(t_flag *f);

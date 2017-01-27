#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef struct	s_var
{
	int zero;
	int space;
}				t_var;

int		ft_printf(const char *format, ...);
int		ft_count_arg(const char *format);
int		ft_gestion_zero(const char *format, int i);
int		ft_gestion_plus(const char *format, int i);
int		ft_gestion_moins(const char *format, int i);
int		ft_string(const char *format, va_list arg, int i , t_var *g);
int		ft_int(const char *format, va_list arg, int i, t_var *g);
int		ft_addr(const char *format, va_list arg, int i, t_var *g);
int		ft_octal(const char *format, va_list arg, int  i, t_var *g);
int		ft_unsigned_int(const char *format, va_list arg, int i, t_var *g);
int		ft_hexa_min(const char *format, va_list arg, int i, t_var *g);
int		ft_hexa_max(const char *format, va_list arg, int i, t_var *g);
int		ft_ll(const char *format, va_list arg, int i, t_var *g);
int		ft_hh(const char *format, va_list arg, int i, t_var *g);
int		ft_long(const char *format, va_list arg, int i, t_var *g);
int		ft_short(const char *format, va_list arg, int i, t_var *g);
#endif

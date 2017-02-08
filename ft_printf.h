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
	int	size;
	char	*Ox;
	char	*s;
}		t_flag;

typedef struct	s_spec
{
	int	(*ptr)();
	char	c;
}		t_spec;

int		ft_printf(const char *format, ...);
void		ft_init_specs1(t_spec *specs);
int		ft_dispatcher(t_flag *f, va_list *ap);
//
//check
//
void		ft_check_flag(t_flag *f);
void		ft_check_width(t_flag *f);
void		ft_check_precision(t_flag *f);
void		ft_check_modifier(t_flag *f);
int		ft_check(t_flag *f);
//handler d
//modifier hhlld
//+ ztd
int		ft_modifier_d(t_flag *f, va_list *ap);
int		ft_handler_wd(t_flag *f, va_list *ap);
int		ft_handler_d(t_flag *f, va_list *ap);
int		ft_handler_hhd(t_flag *f, va_list *ap);
int		ft_handler_hd(t_flag *f, va_list *ap);
int		ft_handler_lld(t_flag *f, va_list *ap);
int		ft_handler_ld(t_flag *f, va_list *ap);
int		ft_handler_jd(t_flag *f, va_list *ap);
int		ft_handler_zd(t_flag *f, va_list *ap);
//handler u
//modifier hhllu
//+ zju
int		ft_modifier_u(t_flag *f);
int		ft_handler_wu(t_flag *f, va_list *ap);
int		ft_handler_u(t_flag *f, va_list *ap);
int		ft_handler_hhu(t_flag *f, va_list *ap);
int		ft_handler_hu(t_flag *f, va_list *ap);
int		ft_handler_llu(t_flag *f, va_list *ap);
int		ft_handler_lu(t_flag *f, va_list *ap);
int		ft_handler_ju(t_flag *f, va_list *ap);
int		ft_handler_zu(t_flag *f, va_list *ap);
//handler o
//modifier hhllo
//+ zjo
int		ft_modifier_o(t_flag *f, va_list *ap);
int		ft_handler_wo(t_flag *f, va_list *ap);
int		ft_handler_o(t_flag *f, va_list *ap);
int		ft_handler_hho(t_flag *f, va_list *ap);
int		ft_handler_ho(t_flag *f, va_list *ap);
int		ft_handler_llo(t_flag *f, va_list *ap);
int		ft_handler_lo(t_flag *f, va_list *ap);
int		ft_handler_jo(t_flag *f, va_list *ap);
int		ft_handler_zo(t_flag *f, va_list *ap);
//handler x
//modifier hhllx
//+ zjx
int		ft_modifier_x(t_flag *f, va_list *ap);
int		ft_handler_wx(t_flag *f, va_list *ap);
int		ft_handler_x(t_flag *f, va_list *ap);
int		ft_handler_hhx(t_flag *f, va_list *ap);
int		ft_handler_hx(t_flag *f, va_list *ap);
int		ft_handler_llx(t_flag *f, va_list *ap);
int		ft_handler_lx(t_flag *f, va_list *ap);
int		ft_handler_jx(t_flag *f, va_list *ap);
int		ft_handler_zx(t_flag *f, va_list *ap);
//
//gestion flag
//
int		ft_flags_char(t_flag *f);
int		ft_flag_Ox(t_flag *f);
int		ft_flag_zero(t_flag *f);
int		ft_flag_moins(t_flag *f);
int		ft_flags_plus(t_flag *f);
int		ft_flags_int(t_flag *f);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handler_x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 22:35:26 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/07 22:49:00 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_modifier_x(t_flag *f, va_list *ap)
{
	if (flag[7] == 1)
		return (ft_handler_hhx(f, ap));
	if (flag[8] == 1)
		return (ft_handler_hx(f, ap));
	if (flag[9] == 1)
		return (ft_handler_llx(f, ap));
	if (flag[10] == 1)
		return (ft_handler_lx(f, ap));
	if (flag[11] == 1)
		return (ft_handler_zx(f, ap));
	if (flag[12] == 1)
		return (ft_handler_tx(f, ap));
	return (0);
}

int		ft_handler_wx(t_flag *f, va_list *ap)
{
	f->arg = ft_xlitoa((unsigned long long int)va_arg(ap, unsigned long int));
	if (flag[1] > ft_strlen(f->arg))
		ft_flags_int(f);
	ft_putstr(f->arg);
	return (0);
}

int		ft_handler_x(t_flag *f, va_list *ap)
{
	if (flag[7] == 1 || flag[8] == 1 ||
		flag[9] == 1 || flag[10] == 1 ||
		flag[11] == 1 || flag[12] == 1)
		ft_modifier_x(f, ap);
	if (flag[7] != 1 && flag[8] != 1 &&
		flag[9] != 1 && flag[10] != 1 &&
		flag[11] != 1 && flag[12] != 1)
		f->arg = ft_xitoa((unsigned int)va_arg(ap, unsigned int));
	if (flag[1] > ft_strlen(f->arg))
		ft_flags_int(f);
	ft_putstr(f->arg);
	return (0);
}
}

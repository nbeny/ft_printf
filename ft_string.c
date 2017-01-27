/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 14:37:14 by nbeny             #+#    #+#             */
/*   Updated: 2017/01/27 15:22:58 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_string(const char *format, va_list arg, int i, t_var g)
{
	char *s;


	s = ft_strdup(va_arg(arg, char *));

}

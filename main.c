/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:57:33 by nbeny             #+#    #+#             */
/*   Updated: 2017/03/01 16:45:24 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>

int		main()
{
	int		ret;

	ret = ft_printf("%%*b : %b\n", 3543442);
	ret = ft_printf("%%*t : %*t\n", 10, 6546);
	ret = ft_printf("%%*d : %6.8d\n", 10, 20, 6546);
	ret = ft_printf("*o : %*.*o\n", 20, 10, 6546);
	ret = ft_printf("%%n : %n\n", 6546);
	ret = ft_printf("%%u : %u\n", 6546);
	ret = ft_printf("%%x : %x\n", 6546);
	ret = ft_printf("%%v : %v\n", 6546);
	return (0);
}

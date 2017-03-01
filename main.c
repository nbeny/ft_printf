/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:57:33 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/27 22:35:10 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>
#include <limits.h>
#include <locale.h>
int		main(int ac, char **av)
{
	int				ret;

	ac = 4;
	(void)av;
        setlocale(LC_ALL, "");
	ret = ft_printf("[%.c]", 0);
	return (0);
}

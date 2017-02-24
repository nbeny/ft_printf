/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 14:57:33 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/20 11:46:13 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
#include <stdio.h>

int		main(int ac, char **av)
{
	int				ret;

	(void)ac;
	(void)av;
	ret = ft_printf("[%*s]\n", 10, "sdfljg");
	ft_printf("[%*.*d]\n", 10, 5, ret);
	return (0);
}

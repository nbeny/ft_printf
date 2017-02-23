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
	unsigned long long int i;
	int						ret;

	(void)ac;
	(void)av;
	i = 4294967295;
	ret = ft_printf("%+u", i);
	printf("%+d", ret);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 09:33:39 by nbeny             #+#    #+#             */
/*   Updated: 2016/11/18 14:47:20 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *s)
{
	unsigned int i;
	unsigned int negatif;
	unsigned int n;

	i = 0;
	negatif = 0;
	n = 0;
	while (s[i] < 33 && s[i] >= 0)
		i++;
	if (s[i] == '-')
		negatif = 1;
	if (s[i] == '-' || s[i] == '+')
		i++;
	while (s[i] >= '0' && s[i] <= '9')
	{
		n = n * 10 + (s[i] - '0');
		i++;
	}
	if (negatif == 1)
		return (-n);
	return (n);
}

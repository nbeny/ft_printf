/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usefull.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:33:41 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/27 20:18:33 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_cpynchar(char *dest, int c, size_t n)
{
	unsigned int i;

	i = 0;
	if (dest)
	{
		while (i < n)
		{
			dest[i] = c;
			i++;
		}
	}
	return (dest);
}

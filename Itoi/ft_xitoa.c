/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 23:16:22 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/07 23:30:39 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char*ft_reverse_itoa(char *itoa)
{
	size_ti;
	size_tj;
	chartmp;

	i = 0;
	j = 0;
	if (itoa[i] == '-')
		i++;
	while (itoa[j])
		j++;
	j--;
	while (i < j)
	{
		tmp = itoa[i];
		itoa[i] = itoa[j];
		itoa[j] = tmp;
		i++;
		j--;
	}
	return (itoa);
}

static size_tft_ccl_malloc(int n)
{
	size_ti;

	i = 0;
	if (n < 0)
	{
		n = n * (-1);
		i++;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	i++;
	return (i);
}

char*ft_itoa(int n)
{
	char*itoa;
	size_ti;
	size_tj;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	j = ft_ccl_malloc(n);
	if (!(itoa = (char *)malloc(sizeof(char) * (j + 1))))
		return (NULL);
	if (n < 0)
	{
		n = n * (-1);
		itoa[i++] = '-';
	}
	while (n > 9)
	{
		itoa[i++] = n % 10 + '0';
		n = n / 10;
	}
	if (n <= 9)
		itoa[i++] = n % 10 + '0';
	itoa[i] = '\0';
	itoa = ft_reverse_itoa(itoa);
	return (itoa);
}

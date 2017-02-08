/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_litoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 23:01:30 by nbeny             #+#    #+#             */
/*   Updated: 2017/02/07 23:10:26 by nbeny            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_reverse_itoa(char *itoa)
{
	size_t	i;
	size_t	j;
	char	tmp;

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

static size_t	ft_ccl_malloc(long long int n)
{
	size_t i;

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

char			*ft_litoa(long long int n)
{
	char	*itoa;
	size_t	i;
	size_t	j;

	if (n == -9223372036854775807)
		return (ft_strdup("-9223372036854775807"));
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

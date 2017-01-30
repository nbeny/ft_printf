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

static char	*ft_space(char *s, int i)
{
	int j;

	j = 0;
	if (!(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (j < i)
	{
		s[j] = ' ';
		j++;
	}
	s[j] = 0;
	return (s);
}

void		ft_string(const char *format, va_list arg, int i, t_var g)
{
	char	*s;
	char	*space;
	char	*strjoin;
	int	i;

	s = ft_strdup(va_arg(arg, char *));
	if (g->s_moins != 0)
		if (g->s_moins > ft_strlen(s))
		{
			i = g->s_moins - ft_strlen(s);
			space = ft_space(i);
			strjoin = ft_strjoin(s, space);
			free(s);
			free(space);
			s = NULL;
			space = NULL;
			ft_putstr(strjoin);
			free(strjoin);
			strjoin = NULL;
			return ;
		}
	ft_putstr(s);
	free(s);
	s = NULL;
}

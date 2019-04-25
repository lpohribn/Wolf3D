/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:26:15 by lpohribn          #+#    #+#             */
/*   Updated: 2017/11/11 16:26:17 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static	int	ft_countdigits(int n)
{
	int i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

static	int	ft_negative(int n)
{
	if (n >= 0)
		return (-1);
	if (n < 0)
		return (1);
	return (0);
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		j;

	j = n;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_countdigits(n);
	str = (n >= 0 ? (char*)malloc(sizeof(char) * i + 1) :
		(char*)malloc(sizeof(char) * ++i + 1));
	if (!str)
		return (NULL);
	if (n < 0)
		n = n * -1;
	str[i] = '\0';
	while (--i >= 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
	}
	if (ft_negative(j) == 1)
		str[0] = '-';
	return (str);
}

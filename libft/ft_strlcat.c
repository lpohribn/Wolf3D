/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 17:12:13 by lpohribn          #+#    #+#             */
/*   Updated: 2017/10/29 17:12:19 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t		ft_strlcat(char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t len_s1;
	size_t len_s2;

	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (n < ft_strlen(s1) + 1)
		return (len_s2 + n);
	while (n - len_s1 - 1 > i && s2[i] != '\0')
	{
		s1[len_s1 + i] = s2[i];
		i++;
	}
	s1[len_s1 + i] = '\0';
	return (len_s1 + len_s2);
}

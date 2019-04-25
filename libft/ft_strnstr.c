/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:24:41 by lpohribn          #+#    #+#             */
/*   Updated: 2017/10/30 13:32:21 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (s2[i] == '\0')
		return (&((char*)s1)[i]);
	while (s1[i] != '\0' && i < len)
	{
		j = 0;
		while (j + i < len && s1[i + j] == s2[j])
		{
			if (s2[j + 1] == '\0')
				return (&((char*)s1)[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}

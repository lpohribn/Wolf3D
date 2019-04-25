/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:43:51 by lpohribn          #+#    #+#             */
/*   Updated: 2017/11/09 15:43:53 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int		ft_countletters(char const *s, char c)
{
	int l;

	l = 0;
	while (s[l] != c && s[l] != '\0')
	{
		l++;
	}
	return (l);
}

static	char	*ft_copy(char *dest, const char *s, char c)
{
	while (*s != c && *s != '\0')
		*dest++ = *s++;
	*dest = '\0';
	return ((char*)s);
}

char			**ft_strsplit(char const *s, char c)
{
	int		j;
	int		k;
	char	**str;
	int		words;

	k = 0;
	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	if (!(str = (char**)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	while (k < words)
	{
		j = 0;
		while (*s == c && *s != '\0')
			s++;
		if (!(str[k] = (char*)malloc(sizeof(char) * ft_countletters(s, c) + 1)))
		{
			ft_free(str);
			return (NULL);
		}
		s = ft_copy(str[k++], s, c);
	}
	str[k] = NULL;
	return (str);
}

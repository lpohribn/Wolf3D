/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpohribn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:15:07 by lpohribn          #+#    #+#             */
/*   Updated: 2017/11/08 18:15:10 by lpohribn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strtrim(char const *s)
{
	size_t		i;
	size_t		j;
	size_t		k;
	char		*str;

	k = 0;
	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while ((s[i] == ' ' || s[i] == '\t' || s[i] == '\n') && s[i] != '\0')
		i++;
	while (s[j + 1] != '\0')
		j++;
	while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j > i)
		j--;
	if (!(str = (char*)malloc(sizeof(char) * (j - i) + 2)))
		return (NULL);
	while (i <= j)
	{
		str[k++] = s[i++];
	}
	str[k] = '\0';
	return (str);
}
